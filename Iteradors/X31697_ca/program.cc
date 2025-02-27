//X31697 Don Camilo
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void inserta_don(vector<string>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == "Camilo") {
            v.insert(v.begin() + i, "Don");
            ++i; // Avancem per evitar un bucle infinit
        }
    }
}

int main() {
    string p;
    vector<string> frase;
    while (cin >> p) frase.push_back(p);
    inserta_don(frase);
    copy(frase.begin(), frase.end(),
         ostream_iterator<string>(cout, " "));
    cout << endl;
}

