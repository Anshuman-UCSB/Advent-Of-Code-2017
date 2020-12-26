input = "input"|>open|>readlines|>y->map(x->split(x, ","),y)
function toCoord(inp)
    d = Dict("n"=>[0,2], "ne"=>[1,1], "se"=>[1,-1], "s"=>[0,-2], "sw"=>[-1, -1], "nw"=>[-1,1])
    crd = [0,0]
    inp = map(x->d[x], inp)
    for v in inp
        crd+=v
    end
    return crd
end

function manhattan(x)
    return (abs(x[1])+abs(x[2]))/2
end

@time begin
    input[1]|>toCoord|>manhattan|>Int|>println
end

@time begin
    function p2(inp)
        d = Dict("n"=>[0,2], "ne"=>[1,1], "se"=>[1,-1], "s"=>[0,-2], "sw"=>[-1, -1], "nw"=>[-1,1])
        crd = [0,0]
        inp = map(x->d[x], inp)
        p2 = 0
        for v in inp
            crd+=v
            p2 = max(p2, manhattan(crd))
        end
        return p2
    end
    input[1]|>p2|>Int|>println
end