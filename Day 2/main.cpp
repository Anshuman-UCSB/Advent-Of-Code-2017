#include <iostream>
#include "../Util/fileReader.h"

using namespace std;

int main(){
    vector<stringstream> dat = fReader("input.txt").read();
    int checks =0;
    for(auto& ss:dat){
        int t;
        int mn, mx;
        ss>>t;
        mn = mx = t;
        while(ss>>t){
            mx = max(t,mx);
            mn = min(t,mn);
        }
        checks+=mx-mn;
    }
    cout<<"Part 1: "<<checks<<endl;

    dat = fReader("input.txt").read();

    checks = 0;
    for(auto& ss:dat){
        int t;
        vector<int> v;
        v.clear();
        while(ss>>t){
            v.push_back(t);
        }
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<v.size();j++){
                if(i!=j && v[i]%v[j] == 0){
                    checks+=v[i]/v[j];
                    goto outLoop;
                }
            }
        }
        outLoop:;
    }
    cout<<"Part 2: "<<checks<<endl;
}