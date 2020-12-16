function valid(x::String)
    x=split(x)
    for i in 1:length(x)-1
        !(x[i] in x[i+1:end]) || return 0
    end
    return 1
end

function valid2(x::String)
    x = map((s)->s|>collect|>sort|>join,split(x))
    for i in 1:length(x)-1
        !(x[i] in x[i+1:end]) || return 0
    end
    return 1
end

"input"|>open|>readlines|>(x)->map(valid,x)|>sum|>println
"input"|>open|>readlines|>(x)->map(valid2,x)|>sum|>println
# lines = readlines(open("input"))
# lines|>println
# "aa bb cc dd ee"|>valid|>println