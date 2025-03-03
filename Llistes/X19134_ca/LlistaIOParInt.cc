#include <iostream>
#include <list>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"
using namespace std;



// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)
void LlegirLlistaParInt(list<ParInt>& l) {
    int p, s;
    bool zero = true;
    while(zero and cin >> p and cin >> s) {
        if ((p + s) == 0) zero = false;
        if (zero) l.push_back(ParInt(p,s));
    }
}



