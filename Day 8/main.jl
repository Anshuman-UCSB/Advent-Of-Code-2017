@time begin
inp = "input"|>open|>readlines|>x->split.(x)

m = Dict("inc"=>+,"dec"=>-,">"=> >,"<"=> <,">="=> >=,"<="=> <=,"=="=> ==,"!="=> !=)

s = Set([r[1] for r in inp]∪[r[5] for r in inp])
regs = Dict([(v,0) for v in s])

let p2 = -1
    for s in inp
        if m[s[6]](regs[s[5]], parse(Int,s[7]))
            regs[s[1]] = m[s[2]](regs[s[1]], parse(Int, s[3]))
        end
        p2 = max(p2, values(regs)...)
    end

    println("Part 1: ",(max(values(regs)...)))
    println("Part 2: ",p2)
end
end