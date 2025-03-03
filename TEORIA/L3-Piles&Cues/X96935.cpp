//X96935 Palíndroms amb piles
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> S;
    int n, e;
    cin >> n;
    for (int i = 0; i < n/2; ++i) {
        cin >> e;
        S.push(e);
    }
    if (n%2 != 0) cin >> e; //ignorem el senar
    
    bool es_pal = true;
    int i = 0;
    while(i < n/2 and es_pal) {
        cin >> e;
        es_pal = S.top() == e;
        S.pop();
        ++i;
    }

    cout << (es_pal?"SI":"NO") << endl;
}