function rev(regs, start, size)
    temp = copy(regs)
    circshift!(temp, regs, -start)
    reverse!(temp, 1, size)
    circshift!(regs, temp, start)
end
function knotHash(input)
    input = map(Int,collect(input))
    append!(input, [17, 31, 73, 47, 23])
    regs = [x for x in 0:255]
    let i=0, skip = 0, hash = ""
        for _ in 1:64
            for l in input
                rev(regs, i, l)
                i+=l+skip
                i%=length(regs)
                skip+=1
            end
        end
        for i in 1:16:255
            dense = string(reduce(xor,regs[i:i+15]), base=16, pad = 2)
            hash = hash*dense
        end
        return hash
    end
end
