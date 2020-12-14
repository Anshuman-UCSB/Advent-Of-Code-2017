#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> m;
    fstream file("input");
    string line;
    int temp;
    while(getline(file, line)){
        m.push_back(vector<int>());
        stringstream ss(line);
        while(ss>>temp){
            m.back().push_back(temp);
        }
    }
    int p1 = 0;
    int mn, mx;
    for(auto& r: m){
        mx = -1;
        mn = INT32_MAX;
        for(auto i: r){
            mx = max(mx, i);
            mn = min(mn, i);
            // cout<<i<<" ";
        }
        p1 += mx-mn;
    }
    cout<<"Part 1: "<<p1<<endl;

    int p2 = 0;
    for(auto& r: m){
        for(int i = 0;i<r.size();i++){
            for(int j = 0;j<r.size();j++){
                if(i!=j){
                    if(r[i]%r[j] == 0){
                        cout<<r[i]<<"/"<<r[j]<<endl;
                        p2+=r[i]/r[j];
                    }
                }
            }
        }
    }

    cout<<"Part 2: "<<p2<<endl;
}