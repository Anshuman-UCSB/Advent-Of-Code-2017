#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    fstream file("input");
    string line;
    getline(file,line);
    vector<char> v;
    bool inGarb = false;
    int trash = 0;
    for(int i = 0;i<line.size();i++){
        if(line[i] == '!'){
            i++;
            continue;
        }
        if(line[i] == '<' && !inGarb){
            inGarb = true;
            continue;
        }
        if(inGarb){
            if(line[i] != '>'){
                trash++;
                continue;
            }
            if(line[i] == '>'){
                inGarb = false;
                continue;
            }
        }
        else
            v.push_back(line[i]);
    }
    for(auto& c:v){
        cout<<c;
    }cout<<endl;

    // At this point v is a vector of just groups ('{' / '}')

    int score = 0;
    int level = 0;
    for(auto& c:v){
        if(c=='{'){
            level++;
            score+=level;
        }
        if(c=='}'){
            level--;
        }
    }
    cout<<"Score is: "<<score<<endl;
    cout<<"There were "<<trash<<" trash values."<<endl;
}
//3949 too low for part 2