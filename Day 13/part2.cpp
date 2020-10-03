#include "../utility.h"


int main(){
    map<int, int> m;
    fstream file("input");
    string line;
    int a, b;
    while(getline(file, line)){
        stringstream ss(line);
        ss>>a>>line>>b;
        m[a] = b;
    }
    for(int delay = 0;;delay++){
        for(auto& p: m){
            if((p.first + delay)%(p.second*2-2) == 0){
                goto endLoop;
            }
        }
        cout<<"Delay of time "<<delay<<" goes through safely."<<endl;
        break;
        endLoop:;
    }
}