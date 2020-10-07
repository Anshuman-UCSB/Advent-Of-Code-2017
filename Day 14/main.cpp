#include "../utility.h"
#include <iomanip>
#include <functional>
#include <numeric>

void reverse(vector<int>& regs, int start, int len){
    for(int i = 0; i < len/2;i++){
        int a = (start+i)%regs.size();
        int b = (start+len-1-i)%regs.size();
        swap(regs[a], regs[b]);
    }
}

string knotHash(string line){
    vector<int> lengths{line.begin(), line.end()};
    vector<int> add = {17, 31, 73, 47, 23};
    lengths.insert(end(lengths), begin(add), end(add));
    int REGSSIZE = 256;
    vector<int> regs(REGSSIZE);
    iota(regs.begin(), regs.end(), 0);
    // cout<<lengths<<endl;
    int ind = 0;
    int stepsize = 0;
    for(int i = 0;i<64;i++)
        for(auto& len: lengths){
            reverse(regs, ind, len);
            ind+=len+stepsize++;
            ind%=regs.size();
            // cout<<regs<<endl;
        }
    
    stringstream out;
    out<<hex<<setfill('0');
    for(int i = 0;i<16;i++){
        out<<setw(2)<<(accumulate(regs.begin()+i*16, regs.begin()+i*16+16,0,bit_xor<void>()));
        // cout<<out.str()<<endl;
    }
    return out.str();
}

const char* hex_char_to_bin(char c)
{
    // TODO handle default / error
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
    return "";
}

string hex_str_to_bin_str(const string& hex)
{
    // TODO use a loop from <algorithm> or smth
    string bin;
    for(unsigned i = 0; i != hex.length(); ++i)
       bin += hex_char_to_bin(hex[i]);
    return bin;
}

void virus(vector<vector<bool>>& grid, int x, int y){
    if(x<0 || x>=grid[y].size() || y<0 || y>=grid.size()){
        return;
    }
    if(grid[y][x]){
        grid[y][x] = false;
        virus(grid, x, y-1);
        virus(grid, x, y+1);
        virus(grid, x+1, y);
        virus(grid, x-1, y);
    }
}

int main(){
    string input = "ljoxqyyw";
    input += "-";
    vector<vector<bool>> grid;
    string hsh;
    for(int i = 0;i<128;i++){
        grid.emplace_back();
        hsh = hex_str_to_bin_str(knotHash(input+to_string(i)));
        for(char c:hsh){
            grid.back().push_back(c-'0');
        }
    }
    
    int p1 = 0;
    for(auto& r: grid){
        for(auto c: r){
            p1 += c;
            // cout<<(c?'#':'.');
        }//cout<<endl;
    }

    cout<<"Part 1: "<<p1<<endl;

    int p2 = 0;
    bool done = false;
    string trash;
    while(!done){
        done = true;
        for(int y = 0;y<grid.size();y++){
            for(int x = 0;x<grid[y].size();x++){
                if(grid[y][x]){
                    virus(grid, x, y);
                    p2++;
                    done = false;
                    goto cont;
                }
            }
        }
        cont:;
            // cout << "\033[2J\033[1;1H";
            // trash = "";
            // for(auto& r: grid){
            //     for(auto c: r){
            //         p1 += c;
            //         trash+=(c?'#':'.');
            //     }trash+="\n";
            // }
            // cout<<trash;
        // cin>>trash;
    }
    cout<<"Part 2: "<<p2<<endl;    
}