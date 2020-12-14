x = [parse(Int, i) for i in readlines(open("input.txt"))[1]]
[x[i] for i in 1:length(x) if x[i]==x[mod1(i+length(x)÷2,length(x))]]|>sum|>(x)->println("Part 2: ",string(x))
# append!(x, x[1])
# [x[i] for i in 1:length(x)-1 if x[i] == x[i+1]] |> sum |> string |>(x)->println("Part 1: ",x)
# [x[i] for i in 1:length(x) if x[i] == x[(i+length(x)÷2) %length(x) + 1]] |> sum |>(x)->println("Part 2: ",string(x))

let p2::Int = 0
    for i in 1:length(x)
        # println(x[i]," - ",x[mod1(i+length(x)÷2,length(x))])
        if(x[i]==x[mod1(i+length(x)÷2,length(x))])
            p2+=x[i]
            # x[i]|>println
        end
    end
    p2|>(x)->println("Part 2: ",string(x))
end
# [x[i] for i in 1:length(x) if x[i] == x[(i+length(x)÷2)%length(x) + 1]] |> println
# x = Nothing
# open("input.txt") do file
#     global x = [parse(Int, i) for i in readlines(file)[1]]
#     append!(x, x[1])
# end

