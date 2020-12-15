input = 368078

m = Dict((0,0)=>1)
let i=x=y=length=0
    i+=2
    while i<=input
        length+=1
        for n in 1:length
            x+=1
            m[(x,y)] = i
            i+=1
        end
        for n in 1:length
            y+=1
            m[(x,y)] = i
            i+=1
        end
        length+=1
        for n in 1:length
            x-=1
            m[(x,y)] = i
            i+=1
        end
        for n in 1:length
            y-=1
            m[(x,y)] = i
            i+=1
        end
    end
end

m2 = Dict((0,0)=>1)
f = (x,y)->sum(map((x,y)->get(m2,(x,y),0),[(x,y) for i=x-1:x+1, j=y-1:y+1]))

let x=y=length=0
    
    while f(x,y)<=input
        length+=1
        for n in 1:length
            x+=1
            for dx = -1:1, dy = -1:1
            m2[(x,y)] = f(x,y)
        end
        for n in 1:length
            y+=1
            m2[(x,y)] = f(x,y)
        end
        length+=1
        for n in 1:length
            x-=1
            m2[(x,y)] = f(x,y)
        end
        for n in 1:length
            y-=1
            m2[(x,y)] = f(x,y)
        end
    end
end
end

for x in 1+min(first.(keys(m2))...):-1+max(first.(keys(m2))...)
    for y in 1+min(last.(keys(m2))...):-1+max(last.(keys(m2))...)    
        m2[(y,-x)]|>print
        "  "|>print
    end
    println()
end
first([abs.(p)|>sum for (p,v) in m if v == input])|>println