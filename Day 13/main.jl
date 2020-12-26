@time begin
    raw = map(x->parse.(Int, x),split.(readlines(open("input")),":"))
    check = delay->!any(p->(p[1]+delay)%((p[2]-1)*2)==0,raw)
    let i = 0
        while !check(i)
            i+=1
        end
        i|>println
    end
end