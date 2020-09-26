#include "../Util/fileReader.h"
#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Node{
    string name;
    int weight;
    int sumWeight=-1;
    vector<string> children;
};

void helper(string node, map<string, Node> m);

int main(){
    auto raw = fReader("input").read();
    map<string, Node> m;
    for(auto& c:raw){
        cout<<c.str()<<endl;
        auto temp = Node();
        c>>temp.name;
        string t;
        c>>t;
        temp.weight = stoi(t.substr(1,t.size()-1));
        c>>t;
        while(c>>t){
            if(t.back()==','){
                t = t.substr(0,t.size()-1);
            }
            temp.children.push_back(t);
        }

        m[temp.name] = temp;
    }
    
    "Part 1:";
    
    set<string> roots;
    for(auto& kp: m){
        roots.insert(kp.first);
    }
    for(auto& c: m){
        for(auto& n: c.second.children){
            roots.erase(n);
        }
    }
    cout<<roots.size()<<endl;
    cout<<"P1 answer: "<<*roots.begin()<<endl;
    string head = *roots.begin();

    "Part 2:";
    bool solved = false;
    int tsum;
    while(!solved){
        solved = true;
        for(auto& kp:m){
            if(kp.second.sumWeight!=-1){
                goto skip;
            }
            tsum = 0;
            for (auto& c:kp.second.children){
                if(m[c].sumWeight==-1){
                    goto skip;
                }
                tsum+=m[c].sumWeight;
            }
            kp.second.sumWeight = kp.second.weight + tsum;
            solved = false;            
            skip:;
        }
    }
    for(auto& kp:m){
        cout<<kp.first<<" ("<<kp.second.sumWeight<<")";
        for(auto& c:kp.second.children){
            cout<<" : "<<c;
        }cout<<endl;
    }

    int val;
    
}

void helper(string node, map<string, Node> m){
    int val=-1;
    bool err = false;
    for(auto& c: m[node].children){
        if(val==-1){
            val = m[c].sumWeight;
        }
        if(m[c].sumWeight!=val){
            err = true;
        }
    }
    if(err){
        for(auto& c: m[node].children){
            if(val==-1){
                val = m[c].sumWeight;
            }
            if(m[c].sumWeight!=val){
                err = true;
            }
        }
    }else{
        cout<<"Hit base case on "<<node<<", children all match weight."<<endl;
    }
}