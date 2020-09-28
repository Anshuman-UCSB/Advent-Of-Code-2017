#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>
using namespace std;

int main(){
    
    fstream file("input");
    string line;
    int p1 = 0;
    while(getline(file, line)){
        set<string> st;
        vector<string> v;
        stringstream ss(line);
        while(ss>>line)
            v.push_back(line);
        for(string& s: v){
            vector<int> map(26);
            for(char c: s){
                map[c-'a']++;
            }
            string build = "";
            for(int val: map){
                build+=to_string(val);
                build+="-";
            }
            if(st.insert(build).second == false){
                goto endLoop;
            }
        }
        p1++;
        endLoop:;
    }
    cout<<p1<<endl;
}