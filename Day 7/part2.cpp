#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

struct Node{
    Node(){}
    Node(string line){
        stringstream ss(line);
        ss >> name;
        string temp;
        ss>>temp;
        temp = temp.substr(1,temp.size()-2);
        weight = stoi(temp);
        ss>>temp;
        while(ss>>temp){
            if(temp.back() == ','){
                temp.pop_back();
            }
            children.push_back(temp);
        }
        parent = "";
    }
    string name;
    int weight;
    vector<string> children;
    string parent;
    int sumweight;
};

void updateWeight(string s, map<string, Node>& m){
    for(auto &c: m[s].children){
        updateWeight(c,m);
    }
    m[s].sumweight=m[s].weight;
    for(auto &c: m[s].children){
        m[s].sumweight+=m[c].sumweight;
    }
}

int main(){
    fstream file("input");
    string line;
    map<string, Node> m;
    while(getline(file,line)){
        Node n(line);
        m[n.name] = n;
    }

    for(auto &p: m){
        cout<<p.first <<" : "<<p.second.weight<<endl;
        for(auto& s: p.second.children){
            m[s].parent = p.first;
        }
    }

    // Part 1

    string root;
    for(auto &p: m){
        if(p.second.parent == ""){
            cout<<"Parent node: "<<p.first<<endl;
            root = p.first;
            break;
        }
    }

    // Part 2

    updateWeight(root,m);

    for(auto &p: m){
        cout<<p.first <<" : "<<p.second.sumweight<<endl;
        if(p.second.children.empty()){
            continue;
        }
        int first = m[p.second.children.front()].sumweight;
        for(auto &s: p.second.children){
            
        }
    }
    
}