global last = -1
global ind = 1
regs = [0 for x in 'a':'z']
function snd(str)
    global last
    last = regs[str[5]-'a'+1]
end
function set(str)
    try
        regs[str[5]-'a'+1]=regs[str[7]-'a'+1]
    catch
        regs[str[5]-'a'+1]=parse(Int, str[6:end])
    end
end
function add(str)
    regs[str[5]-'a'+1]+=parse(Int, str[6:end])
end
function mul(str)
    try
        regs[str[5]-'a'+1]*=regs[str[7]-'a'+1]
    catch
        regs[str[5]-'a'+1]*=parse(Int, str[6:end])
    end
end
function mod(str)
    try
        regs[str[5]-'a'+1]%=regs[str[7]-'a'+1]
    catch
        regs[str[5]-'a'+1]%=parse(Int, str[6:end])
    end
end
function rcv(str)
    if regs[str[5]-'a'+1]!=0
        println("recieved ",last)
        global ind=-9
    end
end
function jgz(str)
    global ind
    if regs[str[5]-'a'+1]>0
        str[7:end]
        ind += parse(Int,str[6:end])-1
    end
end
m = Dict()
m["snd"] = snd;m["set"] = set;m["add"] = add;
m["mul"] = mul;m["mod"] = mod;m["rcv"] = rcv;m["jgz"] = jgz;
regs|>println
inp = "input"|>open|>readlines
while ind in 1:length(inp)
    global ind
    inp[ind]|>println
    m[inp[ind][1:3]](inp[ind])
    ind+=1
end
