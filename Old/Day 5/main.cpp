#include <iostream>
#include "../Util/fileReader.h"

using namespace std;

void p1(){
	vector<string> inp = fReader("input").read();
	vector<int> regs(inp.size());
	for(int i = 0;i<inp.size();i++){
		regs[i] = stoi(inp[i]);
	}
	int ind = 0;
	int steps = 0;
	while(ind>=0 && ind<regs.size()){
		int &old = regs[ind];
		ind+=regs[ind];
		old++;
		steps++;
	}
	cout<<"Finished at step "<<steps<<endl;
}
void p2(){vector<string> inp = fReader("input").read();
	vector<int> regs(inp.size());
	for(int i = 0;i<inp.size();i++){
		regs[i] = stoi(inp[i]);
	}
	int ind = 0;
	int steps = 0;
	while(ind>=0 && ind<regs.size()){
		int &old = regs[ind];
		ind+=regs[ind];
		if(old>=3){
			old--;
		}else 
			old++;
		steps++;
	}
	cout<<"Finished at step "<<steps<<endl;
}


int main(){
	p2();
}