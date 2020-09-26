#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

void p1(){
	string line;
	vector<int> reg;
	set<vector<int>> s;
	fstream file = fstream("input");
	while(getline(file,line,'	')){
		reg.push_back(stoi(line));
	}
	// for(auto& c:reg){
	// 	cout<<c<<" ";
	// }cout<<endl;
	int cycle = 0;
	while(s.insert(reg).second){
		int max(reg[0]),ind(0);
		for(int i = 1;i<reg.size();i++){
			if(reg[i]>max){
				ind = i;
				max = reg[i];
			}
		}
		reg[ind] = 0;
		// cout<<"Max: "<<max<<endl;
		for(int i = ind+1;max-->0;i++){
			reg[i%reg.size()]++;
		}
		// for(auto& c:reg){
		// 	cout<<c<<" ";
		// }cout<<endl;
		cycle++;
	}
	cout<<"Took "<<cycle<<" cycles."<<endl;

}
void p2(){
string line;
	vector<int> reg;
	set<vector<int>> s;
	fstream file = fstream("input");
	while(getline(file,line,'	')){
		reg.push_back(stoi(line));
	}
	// for(auto& c:reg){
	// 	cout<<c<<" ";
	// }cout<<endl;
	int cycle = 0;
	while(s.insert(reg).second){
		int max(reg[0]),ind(0);
		for(int i = 1;i<reg.size();i++){
			if(reg[i]>max){
				ind = i;
				max = reg[i];
			}
		}
		reg[ind] = 0;
		// cout<<"Max: "<<max<<endl;
		for(int i = ind+1;max-->0;i++){
			reg[i%reg.size()]++;
		}
		// for(auto& c:reg){
		// 	cout<<c<<" ";
		// }cout<<endl;
		cycle++;
	}
	cout<<"Repeated on ";
	for(auto& c:reg){
		cout<<c<<" ";
	}cout<<endl;
	vector<int> first = reg;
	int loop = 0;
	bool start = false;
	while(reg != first || !start){
		start = true;
		int max(reg[0]),ind(0);
		for(int i = 1;i<reg.size();i++){
			if(reg[i]>max){
				ind = i;
				max = reg[i];
			}
		}
		reg[ind] = 0;
		// cout<<"Max: "<<max<<endl;
		for(int i = ind+1;max-->0;i++){
			reg[i%reg.size()]++;
		}
		// for(auto& c:reg){
		// 	cout<<c<<" ";
		// }cout<<endl;
		loop++;
	}
	cout<<"Loop is size "<<loop<<endl;

}

int main(){
	p2();
}