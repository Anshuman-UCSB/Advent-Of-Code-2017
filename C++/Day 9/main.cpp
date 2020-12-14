#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<char>& v){
    for(auto c: v){
        cout<<c;
    }cout<<endl;
}

int main(){
    fstream file("input");
    string line;
    getline(file, line);
    vector<char> inp;
    for(auto c: line){
        inp.push_back(c);
    }

    //Deal with !
    for(int i =0;i<inp.size();i++){
        if(inp[i] == '!'){
            inp.erase(inp.begin()+i);
            inp.erase(inp.begin()+i);
            i-= 2;
        }
    }

    int totalSize = inp.size();

    //Remove garbage
    bool inGarbage = false;
    for(int i =0 ;i<inp.size();i++){
        if(!inGarbage && inp[i] == '<'){
            inGarbage = true;
            totalSize--;
        }
        if(inGarbage && inp[i] != '>'){
            inp.erase(inp.begin()+i--);
        }else if(inp[i] == '>'){
            totalSize--;
            inp.erase(inp.begin()+i--);
            inGarbage = false;
        }
    }

    //Score
    int p1 = 0;
    int lvl = 0;
    for(auto c: inp){
        if(c == '{')
            lvl++;
        if(c == '}'){
            p1 += lvl--;
        }
    }
    cout<<"Part 1: "<<p1<<endl;
    cout<<"Part 2: "<<totalSize - inp.size()<<endl;
    printVector(inp);
    
}