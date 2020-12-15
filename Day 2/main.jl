inp = [parse.(Int,split(r)) for r in readlines(open("input"))]
[max(x...)-min(x...) for x in [parse.(Int,split(r)) for r in readlines(open("input"))]]|>sum|>(x)->println("Part 1: ",string(x))
sorted = [reverse(sort(r)) for r in inp]#|>println
# function f(x)
#     #take in list
#     for i in 1:length(x), j in i+1:length(x)
#         println(i, " ",j)
#         if(x[i]%x[j] == 0)
#             return x[i]÷x[j]
#         end
#     end
# end
function f2(x)
    for i in 1:length(x), j in i+1:length(x)
        (x[i]%x[j]==0) ? (return(x[i]÷x[j])) : 0
    end
end

map(f2,sorted) |> sum |> (x)->println("Part 2: ",string(x))