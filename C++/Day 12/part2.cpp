#include "../utility.h"
#include <queue>
#include <set>
#include <map>

int main(){
    map<int, vector<int>> m;
    fstream file("input");
    string line;
    int a, b;
    string trash;
    while(getline(file, line)){
        stringstream ss(line);
        ss>>a>>trash;
        while(ss>>b){
            m[a].push_back(b);
            ss>>trash;
        }
    }

    for(auto& p: m){
        cout<<p.first<<": "<<p.second<<endl;
    }

    int groups = 0;
    while(m.size()>0){
        groups++;
        queue<int> q;
        set<int> s;
        int start = (*m.begin()).first;
        q.push(start);
        s.insert(start);
        while(!q.empty()){
            for(auto& i: m[q.front()]){
                if(s.insert(i).second){
                    q.push(i);
                }
            }
            q.pop();
        }
        cout<<"Removing group of size "<<s.size()<<endl;
        for(auto i: s){
            m.erase(i);
        }
    }
    cout<<"Part 2: "<<groups<<endl;


}