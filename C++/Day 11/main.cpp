#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

template<typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "{";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last) 
            out << ", ";
    }
    out << "}";
    return out;
}

struct reduc{
    string a, b, res;
    int cnt;
    reduc(){}
    reduc(string ai, string bi, string c):a(ai), b(bi), res(c){}

    void act(map<string, int>& m){
        while(m[a] && m[b]){
            m[a]--;
            m[b]--;
            if(res != ""){
                m[res]+=1;
            }
        }
    }
};

int getTotal(map<string, int> m, vector<reduc>& reductions){
    for(auto& red: reductions)
        red.act(m);
    int total = 0;
    for(auto& p: m){
        total+=p.second;
    }
    cout<<"Size: "<<total<<endl;
    return total;
}


int main(){
    vector<reduc> reductions;
    reductions.emplace_back("n","s","");    
    reductions.emplace_back("n","se","ne");    
    reductions.emplace_back("n","sw","nw");    
    reductions.emplace_back("ne","s","se");    
    reductions.emplace_back("ne","sw","");    
    reductions.emplace_back("ne","nw","n");
    reductions.emplace_back("se","sw","s");    
    reductions.emplace_back("se","nw","");    
    reductions.emplace_back("se","n","ne");
    reductions.emplace_back("s","nw","sw");    
    reductions.emplace_back("s","n","");    
    reductions.emplace_back("s","ne","se");
    reductions.emplace_back("sw","n","nw");    
    reductions.emplace_back("sw","ne","");    
    reductions.emplace_back("sw","se","s");

    fstream file("input");
    string line;
    getline(file, line);
    stringstream ss(line);
    vector<string> instr;
    map<string, int> dir;
    int p2 = -1;
    while(getline(ss,line,',')){
        instr.push_back(line);
        dir[line]++;
        p2 = max(p2, getTotal(dir, reductions));
    }


    for(auto& red: reductions){
        red.act(dir);
    }

    int p1 = 0;
    for(auto& p: dir){
        p1 += p.second;
        cout<<p.first<<": "<<p.second<<endl;
    }
    cout<<"Part 1: "<<p1<<endl;
    cout<<"Part 2: "<<p2<<endl;
    //8223 too high p2
}