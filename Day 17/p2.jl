@time begin
let ind = 1, p2 = 0, step = 337
    for i in 1:50_000_000
        ind+=step
        ind = mod1(ind, i)
        if ind==1 p2 = i end
        ind+=1
    end
    println(p2)
end
end