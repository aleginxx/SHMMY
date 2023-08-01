#include <iostream>
using namespace std;
int main() {
    int N, M;
    cin >> N; cin >> M;
    int A[N][M], i, j, k, m, sum[N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) cin >> A[i][j];
    }
    for (i = 0; i < N; i++) {
        sum[i] = 0;
        for (j = 0; j < M; j++) sum[i] = sum[i] + A[i][j];
    }
    int x = sum[0];
    for (i = 1; i < N; i++) {
        if (sum[i] < x) {
            x = sum[i];
            m = i;
        }
    }
    bool different = true;
    for (i = 0; i < N; i++) {
        if (x == sum[i]) {
            different = false;
            k = i;
        }
    }
    if (different == false) cout << k + 1 << " " << x << endl;
    else cout << m + 1 << " " << x << endl;
}