#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>

using namespace std;


int main(){
    fstream file("input");
    string line;
    getline(file, line);
    stringstream ss(line);
    int temp;
    vector<int> v;
    while(ss>>temp)
        v.push_back(temp);
    set<vector<int>> s;
    int i;
    for(i=0;s.insert(v).second;i++){
        int ind = 0;
        for(int ti = 1;ti<v.size();ti++){
            ind = v[ti]>v[ind]?ti:ind;
        }
        int temp;
        temp = v[ind];
        v[ind] = 0;

        for(;temp>0;temp--){
            ind = (ind+1)%v.size();
            v[ind]++;
        }
        
        
        // for(auto i: v){
        //     cout<<i<<", ";
        // }cout<<endl;
        
    }
    cout<<"Part 1: "<<i<<endl;
}