inp = parse.(Int, "input"|>open|>readlines)
@time begin
    let ind = 1, p1 = 0
        while true
            try
                old = inp[ind]
                inp[ind] += inp[ind]>=3 ? -1 : 1
                ind+=old
                p1+=1
            catch e
                # e|>println
                break
            end
        end
        # inp|>println
        println("Part 2: ",p1)
    end
end