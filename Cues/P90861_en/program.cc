#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VQ = vector<queue<string>>;

void read_initial_queues(VQ& qs, int n) {
    string line;
    getline(cin, line); // Leer la línea vacía.
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        size_t pos = 0;
        while ((pos = line.find(' ')) != string::npos) {
            qs[i].push(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        if (!line.empty()) qs[i].push(line);
    }
}

void process_commands(VQ& qs, int n) {
    string command;
    while (cin >> command) {
        if (command == "LEAVES") {
            int a;
            cin >> a;
            --a;
            if (a >= 0 and a < n and !qs[a].empty()) {
                cout << qs[a].front() << endl;
                qs[a].pop();
            }
        } else {
            string name;
            int a;
            cin >> name >> a;
            --a;
            if (a >= 0 and a < n) {
                qs[a].push(name);
            }
        }
    }
}

void print_final_contents(VQ& qs) {
    cout << "\nFINAL CONTENTS" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < int(qs.size()); ++i) {
        cout << "queue " << i + 1 << ':';
        while (!qs[i].empty()) {
            cout << ' ' << qs[i].front();
            qs[i].pop();
        } 
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    VQ qs(n);
    
    read_initial_queues(qs, n);
    
    cout << "DEPARTS" << endl;
    cout << "-------" << endl;
    
    process_commands(qs, n);
    
    print_final_contents(qs);
}