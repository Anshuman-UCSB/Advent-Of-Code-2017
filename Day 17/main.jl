step = "input"|>open|>readline|>x->parse(Int, x)
buff = [0]
let ind = 1
    for i in 1:2017
        ind+=step
        ind = mod1(ind, length(buff))
        insert!(buff, ind+1, i)
        ind+=1
    end
    println("Part 1: ",buff[mod1(ind+1, length(buff))])
end