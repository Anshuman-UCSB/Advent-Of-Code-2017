

let lens = "input"|>open|>readline|>x->split(x,",")|>x->parse.(Int, x), regs = [i for i in 0:4]
    curr, skip = 1, 0
    for l in lens
        println("reg : ",regs)
        regs = circshift(regs, -curr)
        regs = reverse(regs, 1, l);
        regs = circshift(regs, curr)
        skip+=1
        curr+=skip
        mod1(curr, length(regs))
    end
    println("reg : ",regs)
end