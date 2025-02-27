// Distribució justa de cues X13425
// program.cc
#include <queue>
#include "ParInt.hh"
#include "CuaIOParInt.hh"

void distribuirCua(std::queue<ParInt>& c, std::queue<ParInt>& c1, std::queue<ParInt>& c2) {
    int t1 = 0, t2 = 0;
    while (!c.empty()) {
        ParInt p = c.front();
        c.pop();
        if (t1 <= t2) {
            c1.push(p);
            t1 += p.segon();
        } else {
            c2.push(p);
            t2 += p.segon();
        }
    }
}

int main() {// CuaIOParInt.hh
#ifndef CUA_IO_PAR_INT_HH
#define CUA_IO_PAR_INT_HH

#include <queue>
#include "ParInt.hh"

void llegirCuaParInt(std::queue<clude ParInt>& c);
void escriureCuaParInt(std::queue<ParInt> c);

#endif
    std::queue<ParInt> c, c1, c2;
    llegirCuaParInt(c);
    distribuirCua(c, c1, c2);
    escriureCuaParInt(c1);
    std::cout << std::endl;
    escriureCuaParInt(c2);
}
