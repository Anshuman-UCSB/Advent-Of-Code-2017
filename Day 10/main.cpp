#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
using namespace std;

int main(){
    //read input from file
    fstream file("input");
    string line;
    getline(file, line);
    int temp;
    char trash;
    stringstream ss(line);
    vector<int> inp;
    /*
    while(ss>>temp){
        inp.push_back(temp);
        ss>>trash;
    }
    */
    while(ss>>trash){
        inp.push_back(trash);
    }
    vector<int> extra = {17, 31, 73, 47, 23};
    inp.insert(inp.end(), extra.begin(), extra.end());
    // for(auto& i: inp){
    //     cout<<i<<endl;
    // }
    
    vector<int> v;
    int SIZE = 256;
    
    for(int i = 0;i<SIZE;i++)
        v.push_back(i);

    // for(auto val: v)
    //     cout<<val<<endl;

    int ind = 0;
    int skip = 0;
    stack<int> s;
    for(int i = 0;i<64;i++){
        for(int len:inp){
            for(int i = 0; i<len;i++){
                s.push(v[(ind+i)%v.size()]);
            }
            for(int i = 0; i<len;i++){
                v[(ind+i)%v.size()] = s.top();
                s.pop();
            }
            // for(auto val: v)
            //     cout<<val<<" ";
            // cout<<endl;
            ind+=len+skip++;
        }
    }
    vector<int> sparse;
    ind = 0;
    for(int i = 0;i<16;i++){
        int val = 0;
        for(int j =0;j<16;j++)
            val ^= v[ind++];
        sparse.push_back(val);
    }

    stringstream hx;
    for(auto val: sparse)
        hx<<setw(2)<<setfill('0')<<hex<<val;


    cout<<"Part 1: "<<v[0]*v[1]<<endl;
    cout<<"Part 2: "<<hx.str()<<endl;
}