#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int i, p, K[1127];
    p = 1;
    for (i = 0; i <= N; i++) {
    while (p <= N) {
        // for (i=0; i<=N; i++) {
        p = p * 2;
        if (N % p == 0) 
            K[i] = i; }
    }
    printf ("%d\n", K[i]);
}
