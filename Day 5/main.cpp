#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    fstream file("input");
    string line;
    vector<int> v;
    while(getline(file, line))
        v.push_back(stoi(line));
    // for(auto& i: v){
    //     cout<< i<<" ";
    // }cout<<endl;
    int i = 0;
    int step = 0;
    int old;
    while(i>=0 && i<v.size()){
        old = i;
        i+=v[i];
        v[old] = v[old]>=3?v[old]-1:v[old]+1;
        step++;
    }
    cout<<step<<endl;
}