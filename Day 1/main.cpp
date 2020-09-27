#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    vector<int> inp;
    fstream file("input");
    string line;
    getline(file, line);
    for(auto c: line)
        inp.push_back(c-'0');
    // inp.push_back(inp.front());
    int out = 0;
    for(int i = 0;i<inp.size();i++){
        if(inp[i] == inp[(i+(inp.size())/2)%inp.size()]){
            cout<<inp[i]<<endl;
            out+=inp[i];
        }
    }
    cout<<out<<endl;
}