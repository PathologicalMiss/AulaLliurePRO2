#include <stack>
#include <iostream>
using namespace std;


int main() {
    stack<char> s;
    char c;
    bool es_bo = true;
    int pos = 0; //posició

    cin >> c;

    while (c != '.' and es_bo) {
        if (c == '(' or c == '[') s.push(c); //obert

        else if(c == ')') { //tancat
            if (s.empty()) es_bo = false;
            else if (s.top() == '(') s.pop();
            else es_bo = false;
        }

        else {                   //tancat
            if (s.empty()) es_bo = false;
            else if (s.top() == '[') s.pop();
            else es_bo = false;
        }


        cin >> c;
        ++pos;
    }


    if (es_bo and s.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte " << pos << endl;
}
