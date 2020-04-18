#include <iostream>
#include <set>
#include "../util/fileReader.h"
#include <sstream>

using namespace std;

void p1(){
	vector<string> v = fReader("input").read();
	int valid = 0;
	for(auto& c:v){
		set<string> s;
		stringstream ss(c);
		string line;
		while(ss>>line){
			if(s.insert(line).second == false){
				goto guh;
			}
		}
		valid++;
		guh:;
		}
	cout<<"Valid passphrases: "<<valid<<endl;
	// 512 too high
}

void p2(){
	vector<string> v = fReader("input").read();
	int valid = 0;
	for(auto& str:v){
		set<vector<int>> s;
		stringstream ss(str);
		string line;
		while(ss>>line){
			vector<int> frq(26,0);
			for(auto& c:line){
				frq[c-'a']++;
			}
			if(s.insert(frq).second==false){
				cout<<"repeat anagram"<<endl;
				goto guh;
			}
		}
		valid++;
		guh:;
	}
	cout<<"Part 2: "<<valid<<endl;
}

int main(){
	p2();
}