#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#define coord pair<int, int>

using namespace std;

int main(){
    map<coord, int> m;
    int inp = 368078;

    int x(0), y(0), num(1);
    int dist = 1;
    int stage = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    m[make_pair(x, y)] = num++;
    while(num<inp){
        for(int i = 0;i<dist;i++){
            x+=dx[stage%4];
            y+=dy[stage%4];
            int val = 0;
            for(int i = 0;i<9;i++){
                int tx = i%3 -1;
                int ty = i/3 -1;
                if(m.count(make_pair(x+tx, y+ty)))
                    val += m[make_pair(x+tx, y+ty)];
            }
            m[make_pair(x,y)] = val;
            cout<<x<<", "<<y<<" - "<<m[make_pair(x,y)]<<endl;
            if(m[make_pair(x,y)] > inp){
                cout<<"Answer: "<<m[make_pair(x,y)]<<endl;
                goto out;
            }
        }
        stage++;
        for(int i = 0;i<dist;i++){
            x+=dx[stage%4];
            y+=dy[stage%4];
            int val = 0;
            for(int i = 0;i<9;i++){
                int tx = i%3 -1;
                int ty = i/3 -1;
                val += m[make_pair(x+tx, y+ty)];
            }
            m[make_pair(x,y)] = val;
            cout<<x<<", "<<y<<" - "<<m[make_pair(x,y)]<<endl;
            if(m[make_pair(x,y)] > inp){
                cout<<"Answer: "<<m[make_pair(x,y)]<<endl;
                goto out;
            }

        }
        stage++;
        dist++;
    }
    out:;
}

/*
int main(){
    map<coord, int> m;
    int inp = 368078;

    int x(0), y(0), num(1);
    int dist = 1;
    int stage = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    m[make_pair(x, y)] = num++;
    while(num<inp){
        for(int i = 0;i<dist;i++){
            x+=dx[stage%4];
            y+=dy[stage%4];
            m[make_pair(x,y)] = num++;
        }
        stage++;
        for(int i = 0;i<dist;i++){
            x+=dx[stage%4];
            y+=dy[stage%4];
            m[make_pair(x,y)] = num++;
        }
        stage++;
        dist++;
    }

    for(auto& p: m){
        if(p.second == inp){
            cout<<"Part 1: "<<abs(p.first.first)+abs(p.first.second)<<endl;
        }
        // cout<<p.first.first<<", "<<p.first.second<<" - "<<p.second<<endl;
    }
}
*/