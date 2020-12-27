@time begin
include("../Day 10/main.jl")
input = "input"|>open|>readline
function getRow(input, i)
    s = input*"-"*string(i)
    kHash = knotHash(s)
    out = []
    for c in kHash
        d = digits(parse(Int, c, base=16), base = 2, pad = 4)
        reverse!(d)
        append!(out, d)
    end
    return out
end
grid = [getRow(input,x) for x in 0:127]
println("Part 1: ",(grid|>x->reduce.(+,x)|>sum))
grid =map.(x->x==1 ? "#" : ".",grid)
@label repeat
let p2 = 0
    for y in 1:length(grid), x in 1:length(grid)
    # for y in 1:8, x in 1:8
        if grid[y][x] == "#"
            p2+=1
            grid[y][x] = string(p2)
            s = []
            push!(s, (y,x))
            while !isempty(s)
                coord = pop!(s)
                dxy = [[0,1],[1,0],[0,-1],[-1,0]]
                for d in dxy
                    if (0<coord[1]+d[1]<=128 && 0<coord[2]+d[2]<=128) && grid[coord[1]+d[1]][coord[2]+d[2]] == "#"
                        push!(s, (coord[1]+d[1], coord[2]+d[2]))
                        grid[coord[1]+d[1]][coord[2]+d[2]] = string(p2)
                    end
                end
            end
        end
    end
    # println.(map(join, grid[1:20]))
    println(p2)
end
end