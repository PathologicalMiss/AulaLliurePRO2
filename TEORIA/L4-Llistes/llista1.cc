#include <iostream>
#include <list>
using namespace std;


int main() {
    //declaració list<T> nom
    list<int> l;
    l.insert(l.end(), 1);
    l.insert(l.end(), 1);
    l.insert(l.end(), 1);
    int s = 0;
    // for (int elem : l) {
    //     s += elem;
    // }
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); ++it) {
        s += *it;
    }
    cout << "Sum of all elements: " << s << endl;
}