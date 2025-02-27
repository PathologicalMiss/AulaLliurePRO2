
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

string join(vector<string>::iterator ini, vector<string>::iterator fin, string sep) {
    string result;
    if (ini != fin) {
        result = *ini;
        ++ini;
    }
    while (ini != fin) {
        result += sep + *ini;
        ++ini;
    }
    return result;
}

int main() {
   string sep, L, x;
   vector<string> v;
   getline(cin, L);
   sep = L.substr(1, L.size() - 2);
   getline(cin, L);
   istringstream S(L);
   while (S >> x) { v.push_back(x); }
   cout << '"' << join(v.begin(), v.end(), sep) << '"' << endl;
}
