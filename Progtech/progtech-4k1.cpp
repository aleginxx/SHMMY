#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N; cin >> M;
    int array[N], x, y, num_odd = 0;
    for (int j = 0; j < N; j++) array[j] = 0;
    for (int i = 0; i < M; i++) {
        cin >> x; 
        cin >> y; 
        array[x]++; array[y]++; /*cout << "node " << x << " is " << array[x] << " and node " << y << " is " << array[y] << endl;*/
    }
    bool allEven = true, allOdds = true;
    for (int h = 0; h < N; h++) {
        if (array[h] % 2 != 0) {
            allEven = false;
            num_odd++;
        }
        if (array[h] % 2 == 0) allOdds = false;
    }
    // cout << num_odd << endl;
    if (allEven == false && allOdds == true) cout << "IMPOSSIBLE" << endl;
    else if (allEven == true && allOdds == false) cout << "CYCLE" << endl;
    else {
        int u = -1, v = -1, k = 0, g = N - 1;
        if (num_odd != 2) cout << "IMPOSSIBLE" << endl;
        else {
            while (k < N) {
                if ( (array[k] % 2 != 0) && (k != N - 1) && (array[k + 1] % 2 == 0)) u = k;
                if (u != -1) break;
                else k++;
            }
            while (g >= 0) {
                if ( (array[g] % 2 != 0) && (g != 0) && (array[g - 1] % 2 == 0) ) v = g;
                if (v != -1) break;
                else g--;
            }
            if (u == -1 || v == -1) {
                k = 0;
                while (k < N) {
                    if ( (array[k] % 2 != 0) && (k != N - 1) && (array[k + 1] % 2 != 0)) u = k;
                    if (u != -1) break;
                    else k++;
                }
                v = u + 1;
            }
            cout << "PATH " << u << " " << v << endl;
        }
    }
}
