#include <iostream>
#include <fstream>
#include <string>
#include "../Util/fileReader.h"

using namespace std;

int main(){
    fReader file("input.txt");
    vector<string> dat = file.read();
    string inp = dat[0];
    inp.push_back(inp[0]);
    int sum = 0;
    for(int i =0;i<inp.size()-1;i++){
        if(inp[i] == inp[i+1]){
            sum+=inp[i]-'0';
        }        
    }
    cout<<"P1: "<<sum<<endl;

    inp.pop_back();
    int jump = inp.size()/2;
    sum = 0;
    for(int i = 0;i<inp.size();i++){
        if(inp[i] == inp[(i+jump)%(2*jump)]){
            sum+=inp[i]-'0';
        }  
    }
    cout<<"P2: "<<sum<<endl;
}