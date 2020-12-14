#include "../utility.h"

struct Scanner{
    int id, loc, size;
    bool down;
    Scanner(){size =-1;}
    Scanner(string inp){
        stringstream ss(inp);
        string trash;
        loc = 0;
        ss>>id>>trash>>size;
        down = true;
    }

    void reset(){
        loc = 0;
        down = true;
    }

    void act(){
        if(loc == size-1){
            down = false;
        }
        if(loc == 0){
            down = true;
        }
        if(down){
            loc++;
        }else
            loc--;
    }

    
};

ostream& operator<< (ostream& out, const Scanner& s) {
    for(int i =0;i<s.size;i++){
        out<<"["<<(s.loc==i?"S":" ")<<"] ";
    }
    return out;
}

int main(){
    map<int, Scanner> m;
    int fireWallSize = -1;
    fstream file("input");
    string line;
    while(getline(file, line)){
        Scanner temp(line);
        m[temp.id] = temp;
        fireWallSize = max(fireWallSize, temp.id);
    }
    for(int i = 0;i<=fireWallSize+1;i++){
        m[i];
    }
    int pos = -1;
    int delay = -1;
    int score = -1;
    while(score){
        startLoop:;
        delay++;
        for(auto& p: m){
            p.second.reset();
            for(int i = 0;i<delay;i++){
                p.second.act();
            }
        }
        pos = -1;
        
        score = 0;
        while(pos<=fireWallSize){
            if(m[++pos].loc == 0){
                score += pos*m[pos].size;
                // cout<<"Delay is "<<delay<<endl;
                goto startLoop;
            }
            for(auto& p: m){
                p.second.act();
                // cout<<p.first<<": "<<p.second.loc<<"/"<<p.second.size<<endl;
            }
        }
        cout<<"Score after waiting "<<delay<<": "<<score<<endl<<endl;
    }
}