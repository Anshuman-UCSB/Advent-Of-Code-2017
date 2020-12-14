#include "../utility.h"

struct Generator{
    unsigned long long int v;
    int mult;
    int div = INT32_MAX;
    Generator(){}
    Generator(int start, int factor):v(start), mult(factor){}
    void act(){
        v*=mult;
        v%=div;
    }
    int checksum(){
        return v%65536;
    }

};

int main(){
    int p1 = 0;
    pair<Generator, Generator> gens = make_pair(Generator(512, 16807), Generator(191, 48271));
    // pair<Generator, Generator> gens = make_pair(Generator(65, 16807), Generator(8921, 48271));
    for(unsigned int i = 0;i<40000000;i++){
        p1 += gens.first.checksum() == gens.second.checksum();
        while()
        gens.first.act();
        gens.second.act();
    }
    cout<<"Part 1: "<<p1<<endl;
}
