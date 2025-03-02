#include <iostream>
#include <queue>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const queue<T>& q) {
    queue<T> copy = q;
    os << "[";
    while (!copy.empty()) {
        os << copy.front();
        copy.pop();
        if (!copy.empty()) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main() {
    //declaració queue<T> nom;
    queue<int> q;

    //inserir element
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q << endl;

    //accedir a l'últim element afegit (front)
    cout << "el front de la cua és " << q.front() << endl;
    //eliminar l'últim element afegit (front)
    q.pop();
    cout << "front de la cua eliminat" << endl;
    cout << "el front de la cua és " << q.front() << endl <<endl;


    //mida de la cua
    cout << "la mida de la cua és " << q.size() << " element/s" << endl;
    q.pop();
    cout << "front de la cua eliminat" << endl;

    cout << "la mida de la cua és " << q.size() << " element/s" << endl << endl;


    //comprovar si la cua està buida
    if (q.empty()) cout << "cua buida" << endl;
    else cout << "la cua NO es troba buida, té " << q.size() << " element/s" << endl;
    
    //eliminem elemens fins que la pila es trobi buida
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        cout << "element " << front << " eliminat, queden " << q.size() << " element/s" << endl; 
    }
    if (q.empty()) cout << "cua buida" << endl; 

}