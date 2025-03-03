//X84889 Guanyadors

#include <iostream>
#include <vector>
using namespace std;

struct Player {
    string name;
    int score;
};

vector<string> winners(vector<Player>::iterator ini, vector<Player>::iterator fin) {
    vector<string> w;
    int max = 0;
    while (ini != fin) {
        if (ini->score > max) {
            max = ini->score;
            w.clear();
            w.push_back(ini->name);
        }
        else if (ini->score == max) w.push_back(ini->name);
        ++ini;
    }
    return w;
}

int main() {
	Player p;
	vector<Player> v;
	while (cin >> p.name >> p.score) {
		v.push_back(p);
	}
	vector<string> w = winners(v.begin(), v.end());
	for (int i = 0; i < w.size(); i++) {
		cout << (i == 0 ? "" : " ") << w[i];
	}
	cout << endl;
	return 0;
}
