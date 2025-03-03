//X51420 Paraula més llarga

#include <iostream>
#include <vector>
using namespace std;

vector<string>::const_iterator longest(const vector<string>& v) {
    int max_long = 0;
    auto max = v.end();
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it->size() > max_long) {
            max_long = it->size();
            max = it;
        }
    }
    return max;
}

int main() {
   string p;
   vector<string> frase;
   while (cin >> p) frase.push_back(p);
   vector<string>::const_iterator i = longest(frase);
   if (i != frase.end()) {
      cout << *i << endl;
   }
}
