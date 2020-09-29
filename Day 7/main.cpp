#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

struct disc{
    string id;
    int weight;
    vector<string> children;
    disc(){}
    disc(string raw){
        //fwft (72) -> ktlj, cntj, xhth
        stringstream ss(raw);
        char temp;
        string trash;
        ss>>id>>temp>>weight>>trash>>trash;
        while(ss>>trash){
            if(trash.back() == ',')
                trash.pop_back();
            children.push_back(trash);
            // cout<<children.back()<<endl;
        }
        // cout<<id<<endl;
        // cout<<weight<<endl;
    }
    
};

int getWeight(disc& d, map<string, disc>& m){
    // cout<<"getting weight for "<<d.id<<endl;
    int out = d.weight;
    for(auto s:d.children){
        out+=getWeight(m[s],m);
    }
    return out;
}

bool isBalanced(disc& d, map<string, disc>& m){
    if(!d.children.size())
        return true;
    int val = m[d.children[0]].weight;
    for(int i = 1;i<d.children.size();i++){
        if(m[d.children[i]].weight!=val){
            return false;
        }
    }
    return true;
}

string getOutlier(disc& d, map<string, disc>& m){
    if(d.children.size() == 2){
        cout<<"FUCK"<<endl;
        exit(1);
    }
    int val = 0;
    map<int, vector<string>> t;
    for(auto& s: d.children){
        t[getWeight(m[s], m)].push_back(s);
        // cout<<val<<endl;
    }

    for(auto& p: t){
        if(p.second.size() == 1){
            return p.second.front();
        }
    }
    return "NULL";
}

void printChildren(string base, map<string, disc>& m){
    for(auto& c: m[base].children){
        cout<<">"<<c<<"   \t"<<getWeight(m[c],m)<<endl;
    }
}

int main(){
    map<string, disc> m;
    set<string> disks;
    fstream file("input");
    string line;
    while(getline(file, line)){
        disc temp(line);
        disks.insert(temp.id);
        m[temp.id] = temp;
    }
    
    for(auto& p: m){
        for(string& s: p.second.children){
            disks.erase(s);
        }    
    }
    cout<<"Part 1: "<<*disks.begin()<<endl;
    string base = *disks.begin();
    printChildren(base, m);
    string temp = base;
    while(true){
        cin>>temp;
        printChildren(temp, m);
    }

}