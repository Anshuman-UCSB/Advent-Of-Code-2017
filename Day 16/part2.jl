input = "input"|>open|>readline|>x->split(x, ',')
m = Dict([x=>x-'a' for x in 'a':'p'])
func = Dict()
function shift(m, s)
	len = parse(Int,s[2:end])
	for (a, b) in m
		m[a]+=len
		m[a]%=length(m)
	end
end
function exchange(m, s)
	search = parse.(Int,split(s[2:end],"/"))
	a = [k for (k,v) in m if v ∈ search]
	m[a[1]], m[a[2]]= m[a[2]],m[a[1]]
end
function partner(m, s)
	a, b = map(x->x[1],split(s[2:end],'/'))
	m[a], m[b] = m[b], m[a]
end
func['s'] = shift
func['x'] = exchange
func['p'] = partner

function printMap(m)
	out = ""
	for i in 0:length(m)-1
		for (k, v) in m
			if v == i
				out = out*k
				break
			end
		end
	end
	return out
end
for iter in 1:16
	for inp in input
		func[inp[1]](m, inp)
	end
	if printMap(m) == "abcdefghijklmnop"
		iter|>println
	end
end
m|>printMap|>println