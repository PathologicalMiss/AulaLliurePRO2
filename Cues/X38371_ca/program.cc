//X38371 Estadístiques d’una seqüència d’enters amb esborrat 
/*
 * Programa per processar una seqüència d'enters entre -1000 i 1000, amb eliminacions (-1001).
 * - Manté una cua per gestionar l'ordre d'entrada.
 * - Calcula min, max i mitjana en cada operació.
 * - Si s'elimina un element que afectava min o max, es recalculen.
 * 
 * Optimització:
 * - La suma es manté acumulada per evitar recalcular-la completament cada vegada.
 * - El mínim i el màxim només es recalculen si l'element eliminat era igual a un d'ells, evitant recorreguts innecessaris.
 */

#include <iostream>
#include <queue>
#include <limits>
using namespace std;

int main() {
    queue<int> q;  // Cua per mantenir els elements en ordre d'entrada
    int num;
    long long sum = 0;  // Suma acumulada per calcular la mitjana eficientment
    int min_val = numeric_limits<int>::max();
    int max_val = numeric_limits<int>::min();
    
    while (cin >> num) {
        if (num > 1000 || num < -1001) {
            break;  // Fi de la seqüència
        }
        
        if (num == -1001) {  // Eliminació del primer element de la cua
            if (!q.empty()) {
                int removed = q.front();
                q.pop();
                sum -= removed;
                
                if (q.empty()) {
                    cout << "0" << endl;
                    min_val = numeric_limits<int>::max();
                    max_val = numeric_limits<int>::min();
                    continue;
                }
                
                // Si l'element eliminat era min o max, recalculem
                if (removed == min_val || removed == max_val) {
                    min_val = numeric_limits<int>::max();
                    max_val = numeric_limits<int>::min();
                    queue<int> temp = q;
                    while (!temp.empty()) {
                        int val = temp.front();
                        temp.pop();
                        if (val < min_val) min_val = val;
                        if (val > max_val) max_val = val;
                    }
                }
            } else {
                cout << "0" << endl;
                continue;
            }
        } else {  // Nou nombre afegit a la cua
            q.push(num);
            sum += num;
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }
        
        // Mostrem estadístiques actuals
        if (!q.empty()) {
            double avg = static_cast<double>(sum) / q.size();
            cout << "min " << min_val << "; max " << max_val << "; media ";
            if (avg == static_cast<int>(avg)) {
                cout << static_cast<int>(avg) << endl;
            } else {
                cout << avg << endl;
            }
        }
    }
}