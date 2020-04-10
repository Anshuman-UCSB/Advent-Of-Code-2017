#ifndef FILEREAD_H
#define FILEREAD_H

#include <vector>
#include <fstream>
using namespace std;

class fReader{
    public:
    string fname;
    fstream file;
    fReader(string name){
        fname = name;
        file = fstream(name);
    }
    vector<string> read(){
        vector<string> out;
        string line;
        while(getline(file,line)){
            out.push_back(line);
        }
        file.close();
        return out;
    }
};


#endif