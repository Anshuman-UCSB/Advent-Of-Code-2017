parsed = [parse.(Int,[x.match for x in eachmatch(r"\d+", x)]) for x in "input"|>open|>readlines]
@time begin
    let s = Set(0)
        done = false
        while !done
            done = true
            for x in parsed
                if x∩s|>!isempty && setdiff(x,s)|>!isempty
                    s = x∪s
                    done = false
                end
            end
        end
        s|>length|>println
    end
end
p2 = map(x->Set(x), parsed)
groups = []
for i in p2
    # println("trying to find spot for ", i)
    inserted = false
    for g in groups
        # println(i,"∩",g," = ", i∩g)
        if i∩g|>!isempty
            # println(" > ",i,"∪",g," = ", i∪g)
            for e in i
                push!(g, e)
            end
            inserted = true
            # println(groups)
        end
    end
    if !inserted
        push!(groups, i)
    end
end
print("Part 2: ")
groups|>length|>println
