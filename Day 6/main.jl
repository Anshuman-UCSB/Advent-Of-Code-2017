inp = "input"|>open|>readline|>split|>(x)->parse.(Int, x)
inp|>println

function iter(inp)
    mx = max(inp...)
    mxI = findfirst(isequal(mx), inp)
    out = inp
    out[mxI] = 0
    for step in 1:mx
        out[mod1(mxI+step,length(out))]+=1
    end
    return out
end
@time begin
    let temp = inp, count = 0, count2 = 1
        s = Set()
        while temp ∉ s
            count+=1
            push!(s, temp|>copy)
            temp = iter(temp)
        end
        # temp|>println
        check = temp|>copy
        temp = iter(temp)
        while temp != check
            count2+=1
            temp = iter(temp)
        end
        # s|>println
        println("Part 1: ",count)
        println("Part 2: ",count2)
    end
end