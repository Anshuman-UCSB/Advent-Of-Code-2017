input = "input"|>open|>readline|>x->split(x, ',')
function exchange(regs, a, b)
    regs[a+1], regs[b+1] = regs[b+1], regs[a+1]
end
function partner(regs, a, b)
    ia, ib = findfirst(x->x==a,regs), findfirst(x->x==b,regs)
    exchange(regs, ia-1, ib-1)
end
@time begin
let regs = [x for x in 'a':'p']
        for instr in input
            if instr[1] == 's'
                regs = circshift(regs,parse(Int, instr[2:end]))
            elseif instr[1] == 'x'
                a, b = parse.(Int,split(instr[2:end],'/'))
                exchange(regs, a, b)
            elseif instr[1] == 'p'
                a, b = split(instr[2:end],'/')
                partner(regs, a[1], b[1])
            end
        end
    regs|>join|>println
end
end