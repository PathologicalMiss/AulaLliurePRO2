#include <iostream>
#include <stack> //Classe stack
using namespace std;


template <typename T>
ostream& operator<<(ostream& os, const stack<T>& s) {
    stack<T> copy = s;
    os << "[";
    while (!copy.empty()) {
        os << copy.top();
        copy.pop();
        if (!copy.empty()) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main() {
    //declaració stack<T> nom;
    stack<int> s;

    //inserir element
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s << endl;

    //accedir a l'últim element afegit (top)
    cout << "el top de la pila és " << s.top() << endl;
    //eliminar l'últim element afegit (top)
    s.pop();
    cout << "top de la pila eliminat" << endl;
    cout << "el top de la pila és " << s.top() << endl << endl;


    //mida de la pila
    cout << "la mida de la pila és " << s.size() << " element/s" << endl;
    s.pop();
    cout << "top de la pila eliminat" << endl;

    cout << "la mida de la pila és " << s.size() << " element/s" << endl << endl;

    //comprovar si la pila està buida
    if (s.empty()) cout << "pila buida" << endl;
    else cout << "la pila NO es troba buida, té " << s.size() << " element/s" << endl;
    
    //eliminem elemens fins que la pila es trobi buida
    while(!s.empty()) {
        int top = s.top();
        s.pop();
        cout << "element " << top << " eliminat, queden " << s.size() << " element/s" << endl; 
    }
    if (s.empty()) cout << "pila buida" << endl; 

}