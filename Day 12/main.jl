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
done = false
while !done
    done = true
    for x in p2, i in 1:length(p2)
        if x∩p2[i]|>!isempty && x≠p2[i]
            x = x∪p2[i]
            println("x: ",x)
            println("y: ",p2[i])
            deleteat!(p2, i)
            done = false
            break
        end
    end
end