#include <iostream>
using namespace std;
int main() {
    int N; cin >> N;
    int a[N], i, j, odd, even, width[N], k = 0, allodds = 0, allevens = 0;
    for (i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) allevens++;
        else allodds++;
    }
    if (allodds == allevens) {
        cout << N << endl;
        return 0;
    }
    else if (allodds == 0 || allevens == 0) {
        cout << "0" << endl;
        return 0;
    }
    for (i = 0; i < N; i++) {
        even = 0; odd = 0; width[k] = 0;
        if (a[i] % 2 == 0) even++;
        else odd++;
        for (j = (i + 1); j < N; j++) {
            if (a[j] % 2 == 0) even++;
            else odd++;
            if (even == odd) {
                if (k == 0) {
                    width[k] = even + odd;
                    k++;
                }
                else if (even + odd > width[k - 1]) {
                    width[k] = even + odd;
                    k++;
                }
            }
        }
    }
    if (k == 0) {
        cout << "0" << endl;
        return 0;
    }
    else cout << width[k - 1] << endl;
}