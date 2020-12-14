#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

int main(){
    fstream file("input");
    string line;
    vector<string> raw;
    while(getline(file, line)){
        raw.push_back(line);
    }

    map<string, int> regs;
    string a, instr, trash, c1, sign;
    int b, c2;
    string mx = "null";
    int mxVal = -1;
    for(auto& l: raw){
        stringstream ss(l);
        ss>>a>>instr>>b>>trash>>c1>>sign>>c2;
        if(instr == "dec")
            b *= -1;
        bool cond;
        if(sign == ">")
            cond = regs[c1]>c2;
        else if(sign == "<")
            cond = regs[c1]<c2;
        else if(sign == "==")
            cond = regs[c1]==c2;
        else if(sign == "!=")
            cond = regs[c1]!=c2;
        else if(sign == "<=")
            cond = regs[c1]<=c2;
        else if(sign == ">=")
            cond = regs[c1]>=c2;
        if(cond)
            regs[a]+=b;
        // cout<<l<<endl;
        // for(auto& p: regs){
        //     cout<<p.first<<" = "<<p.second<<endl;
        // }cout<<endl;
        for(auto& p: regs){
            if(mx == "null")
                mx = p.first;
            if(p.second > mxVal){
                mx = p.first;
                mxVal = p.second;
            }
        }
    }

    cout<<mx<<" = "<<mxVal<<endl;

}