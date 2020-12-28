# regs = map(split,"input"|>open|>readlines)|>y->parse.(Int,map(x->x[end],y))
@time begin
regs = [512, 191]
let p1=0
    for iter in 1:5000000
        if regs[1]%65536 == regs[2]%65536
            p1+=1
            iter|>println
        end
        regs[1] = (regs[1]*16807)%2147483647
        while regs[1]%4!=0
            regs[1] = (regs[1]*16807)%2147483647
        end
        regs[2] = (regs[2]*48271)%2147483647
        while regs[2]%8!=0
            regs[2] = (regs[2]*48271)%2147483647
        end
    end
end
end