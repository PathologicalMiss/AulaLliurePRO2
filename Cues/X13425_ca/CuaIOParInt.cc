// CuaIOParInt.cc
#include "CuaIOParInt.hh"
#include <iostream>

void llegirCuaParInt(std::queue<ParInt>& c) {
    ParInt p;
    while (p.llegir() && !(p.primer() == 0 && p.segon() == 0)) {
        c.push(p);
    }
}

void escriureCuaParInt(std::queue<ParInt> c) {
    while (!c.empty()) {
        ParInt p = c.front();
        c.pop();
        std::cout << p.primer() << " " << p.segon() << std::endl;
    }
}
