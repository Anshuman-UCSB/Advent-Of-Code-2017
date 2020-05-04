#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main(){
    map<string, int> m;
    fstream file("input");
    string line;
    int relMax = -1;
    while(getline(file,line)){
        stringstream ss(line);
        string target;
        ss>>target;
        string temp;
        ss>>temp;
        string tval;
        ss>>tval;
        int val;
        if(temp == "inc")
            val = stoi(tval);
        else
            val = -1 * stoi(tval);
        ss>>temp;
        string cond;
        ss>>cond;
        string oper;
        ss>>oper;
        ss>>temp;
        int criteria = stoi(temp);

        if(oper == "<"){
            if(m[cond]<criteria){
                m[target]+=val;
            }
        }
        if(oper == ">"){
            if(m[cond]>criteria){
                m[target]+=val;
            }
        }
        if(oper == ">="){
            if(m[cond]>=criteria){
                m[target]+=val;
            }
        }
        if(oper == "<="){
            if(m[cond]<=criteria){
                m[target]+=val;
            }
        }
        if(oper == "=="){
            if(m[cond]==criteria){
                m[target]+=val;
            }
        }
        if(oper == "!="){
            if(m[cond]!=criteria){
                m[target]+=val;
            }
        }
        relMax = max(relMax, m[target]);
    }
    int mx = (*m.begin()).second;
    for(auto& p: m){
        cout<<p.first<<" : "<<p.second<<endl;
        mx = max(mx, p.second);
    }
    cout<<"Max reg is "<<mx<<endl;
    cout<<"Local max is "<<relMax<<endl;
}