@time begin
inp = "input"|>open|>readline|>x->[c for c in x]
while '!' in inp
    ind = findfirst(isequal('!'), inp)
    splice!(inp, ind:ind+1)
end
groups = []
let inTrash = false
    for c in inp
        inTrash = c == '<' ? true : c == '>' ? false : inTrash
        if !inTrash
            append!(groups, c)
        end
    end
end
cleaned = [v for v in groups if v == '{' || v == '}']
# groups|>join|>println

let part1 = 0, level = 0
    for c in cleaned
        if c == '{'
            level+=1
            part1+=level
        else
            level-=1
        end
    end

    println("Part 1: ",part1)
end
# groups|>println
trashCount = count(isequal('>'), groups)
# trashCount|>println
println("Part 2: ",length(inp)-2*trashCount-length(groups))
end