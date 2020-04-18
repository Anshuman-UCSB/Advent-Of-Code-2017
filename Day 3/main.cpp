#include <iostream>
#include <map>

using namespace std;

pair<int,int> crd(int x, int y){
	return pair<int,int>(x,y);
}

void p1(){
	int input = 368078;
	map<pair<int,int>, int> mp;
	int id = 1;
	mp[crd(0,0)] = id++;
	#define log mp[crd(x,y)]=id++
	int x(0),y(0);
	int dist = 0;
	while(id<=input){
		dist++;
		for(int i = 0;i<dist;i++){
			x++;
			if(id == input){
				cout<<"Answer: "<<abs(x)+abs(y)<<endl;
			}
			log;
		}
		for(int i = 0;i<dist;i++){
			y++;
			if(id == input){
				cout<<"Answer: "<<abs(x)+abs(y)<<endl;
			}
			log;
		}
		dist++;
		for(int i = 0;i<dist;i++){
			x--;
			if(id == input){
				cout<<"Answer: "<<abs(x)+abs(y)<<endl;
			}
			log;
		}
		for(int i = 0;i<dist;i++){
			y--;
			if(id == input){
				cout<<"Answer: "<<abs(x)+abs(y)<<endl;
			}
			log;
		}
		
	}
}

#include<vector>
void p2(){
	int input = 368078;
	vector<vector<int>> mp(1000,vector<int>(1000,0));
	int cx(500),cy(500);
	int x(0),y(0);
	mp[cx+x][cy+y] = 1;
	int dist = 0;
	while(true){
		dist++;
		for(int i = 0;i<dist;i++){
			x++;
			for(int dx = -1;dx<=1;dx++){
				for(int dy = -1;dy<=1;dy++){
					if(dx == 0 && dy == 0){
						continue;
					}
					mp[cx+x][cy+y]+=mp[cx+x+dx][cy+y+dy];
				}
			}
			if(mp[cx+x][cy+y] > input){cout<<"Part 2: "<<mp[cx+x][cy+y]<<endl;return;}
		}
		for(int i = 0;i<dist;i++){
			y++;
			for(int dx = -1;dx<=1;dx++){
				for(int dy = -1;dy<=1;dy++){
					if(dx == 0 && dy == 0){
						continue;
					}
					mp[cx+x][cy+y]+=mp[cx+x+dx][cy+y+dy];
				}
			}
			if(mp[cx+x][cy+y] > input){cout<<"Part 2: "<<mp[cx+x][cy+y]<<endl;return;}
		}
		dist++;
		for(int i = 0;i<dist;i++){
			x--;
			for(int dx = -1;dx<=1;dx++){
				for(int dy = -1;dy<=1;dy++){
					if(dx == 0 && dy == 0){
						continue;
					}
					mp[cx+x][cy+y]+=mp[cx+x+dx][cy+y+dy];
				}
			}
			if(mp[cx+x][cy+y] > input){cout<<"Part 2: "<<mp[cx+x][cy+y]<<endl;return;}
		}
		for(int i = 0;i<dist;i++){
			y--;
			for(int dx = -1;dx<=1;dx++){
				for(int dy = -1;dy<=1;dy++){
					if(dx == 0 && dy == 0){
						continue;
					}
					mp[cx+x][cy+y]+=mp[cx+x+dx][cy+y+dy];
				}
			}
			if(mp[cx+x][cy+y] > input){cout<<"Part 2: "<<mp[cx+x][cy+y]<<endl;return;}
		}
	}
}

int main(){
	p2();
}