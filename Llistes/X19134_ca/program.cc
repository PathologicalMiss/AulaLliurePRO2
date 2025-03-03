#include <iostream>
#include <list>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"
using namespace std;

int main() {
    list<ParInt> l;
    LlegirLlistaParInt(l);

    int n, count, suma;
    cin >> n;
    count = 0;
    suma = 0;

    for (list<ParInt>::iterator it = l.begin(); it != l.end(); ++it) {
        if (it->primer() == n) {
            ++count; //parell trobat
            suma += it->segon();
        }
    }

    cout << n << ' ' << count << ' ' << suma << endl;
}
