#include <iostream>
using namespace std;
int main() {
    int N, K; cin >> N; cin >> K;
    int A[N], i, j, x, count, mult = 0, sum[N];
    for (i = 0; i < N; i++) cin >> A[i];
    for (i = 0; i < N; i++) {
        count = 0;
        sum[i] = A[i];
        for (j = (i + 1); j < N; j++) {
            sum[i] += A[j];
            if ( (sum[i] % K == 0) && (sum[i] > mult)) {
                mult = sum[i];
                count++;
            }
        }
        if (count >= (N - i)) break;
    }
    printf("%d\n", mult);
    return 0;
}