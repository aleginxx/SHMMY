#include <iostream>
using namespace std;
int main() {
    int N, i, j, k, count;
    cin >> N;
    int A[N], C[N];
    for (i = 0; i < N; i++) cin >> A[i];
    k = 0;
    for (i = 1; i < N; i++) {
        count = 0;
        for (j = 0; j < i; j++) {
            if (A[j] < A[i]) break;
            if (A[j] % A[i] != 0) break;
            else {
                if (A[j] % A[i] == 0) count++;
                if (count == i) {
                    if (k == 0) C[k] = A[i];
                    else {
                        if (A[i] < C[k]) {
                            C[k] = A[i];
                            k++;
                        }
                    }
                }
            }
        }
    }
    if (C[0] == '\0') cout << A[0] << endl;
    // else {
    //     int x = C[0];
    //     for (int l = 0; l < k; l++) {
    //         if (C[l] < x) x = C[l];
    //     }
    //     cout << x << endl;
    // }
    else cout << C[k] << endl;
}