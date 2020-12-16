struct node
	name::String
	weight::Number
	children::Array
end

function parseInp(x)
	s = split(x)
	name = s[1]
	weight = parse(Int, s[2][2:end-1])
	# fwft (72) -> ktlj, cntj, xhth (EXAMPLE)
	children = [last(x)==',' ? x[1:end-1] : x for x in s[4:end]]
	return node(name, weight, children)
end

totalWeights = Dict()

function isBalanced(n)::Bool
	global totalWeights
	if n.children|>isempty
		return true
	end
	weight = totalWeights[n.children|>first]
	return all(x->isequal(weight,totalWeights[x]), n.children)
end

function findTrouble(n)::String
	global totalWeights
	if n.children|>isempty
		return n
	end
	count = Dict()
	for child in n.children
		wght = totalWeights[child]
		if wght ∈ count|>keys
			count[wght]+=1
		else
			count[wght]=1
		end
	end
	problemWeight = -1
	for (k,v) in count
		v==1 ? (problemWeight = k) : false 
	end
	return n.children[findfirst((x)->totalWeights[x] == problemWeight, n.children)]
end



nodes = [parseInp(x) for x in "input"|>open|>readlines]
children = (reduce(vcat, [n.children for n in nodes]))
names = ([n.name for n in nodes])
( base = setdiff(names, children)|>first)|>x->println("Part 1: ",x)

m = Dict([(n.name, n) for n in nodes])


let changed = true
	while changed == true
		changed = false
		for n in nodes
			if n.name ∉ keys(totalWeights) && all((x)->x ∈ keys(totalWeights),n.children)
				changed = true
				childWeights =  [totalWeights[x] for x in n.children]
				totalWeights[n.name] = n.weight+ (childWeights|>!isempty ? childWeights|>sum : 0)
			end
		end
	end
end
totalWeights|>println

"Part 2"

# m|>println

let temp = base
	while !isBalanced(m[temp])
		temp = findTrouble(m[temp])
		temp|>println
	end
end