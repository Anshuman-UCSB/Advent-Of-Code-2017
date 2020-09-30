#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <queue>
#include <sstream>
#include "../utility.h"
using namespace std;

struct pipe{
    int id;
    vector<int> links;
    pipe(){}
    pipe(string inp){
        stringstream ss(inp);
        string trash;
        ss>>id;
        ss>>trash;
        int temp;
        while(ss>>temp){
            ss>>trash;
            links.push_back(temp);
        }
    }
};

int main(){
    fstream file("input");
    vector<pipe> pipes;
    string line;
    while(getline(file, line))
        pipes.emplace_back(line);
    set<int> s;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int base = q.front();
        q.pop();
        for(int& i: pipes[base].links){
            if(s.insert(i).second){
                q.push(i);
            }
        }
    }
    cout<<"Connected: "<<s.size()<<endl;
}