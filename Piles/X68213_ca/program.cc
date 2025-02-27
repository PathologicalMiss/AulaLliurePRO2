#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


void escriure_llibre(vector<stack<string>>& v, string llibre, int n) {
    v[n-1].push(llibre);
}

void retira_pila(vector<stack<string>>& v, int x, int n) {
    if(not v[n-1].empty()) {
        for (int i = 0; i < x; ++i) {
        v[n-1].pop();
        }
    }
}

void imprimir_pila(vector<stack<string>>& v, int n) {

    cout << "Pila de la categoria " << n << endl;
    vector<stack<string>> v_copia = v;

    while (not v_copia[n-1].empty()) {
        cout << v_copia[n-1].top() << endl;
        v_copia[n-1].pop();
    }
    cout << endl;
}




int main() {

    int n; //#categories
    cin >> n;
    vector<stack<string>> v(n);   // vector de piles de categories n
    string llibre;

    int comanda;
    cin >> comanda;

    while (comanda != -4) {

        if (comanda == -1) {
            cin >> llibre;
            cin >> n;
            escriure_llibre(v, llibre, n);
        }

        else if (comanda == -2) {
            int x;
            cin >> x;
            cin >> n;
            retira_pila(v, x, n);
        }

        else if (comanda == -3) {
            cin >> n;
            imprimir_pila(v, n);
        }

        cin >> comanda;
    }

}
