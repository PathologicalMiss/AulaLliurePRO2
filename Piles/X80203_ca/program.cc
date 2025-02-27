#include <string>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string seq;

    while (cin >> seq) {
        stack<int> s;
        int j = 1;

        for (int i = 0; i < seq.length(); ++i) {
            if (seq[i] == '(') {
                cout << seq[i];
                s.push(j++);
                cout << s.top();
            }

            else {
                cout << seq[i];
                cout << s.top();
                s.pop();
            }

        }
        cout << endl;
    }
}
