#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int A[1127];
    if (N < 10) 
        printf ("%d\n", N);
    else if ( (N >= 10) && (N < 100)) {
        A[1] = N % 10; A[2] = (N/10) % 10;
        printf ("%d\n", (A[1] + A[2]) );
    }
    else if ( (N >= 100) && (N < 1000)) {
        A[1] = N % 10; A[2] = (N/10) % 10; A[3] = (N/100) % 10;
        printf ("%d\n", (A[1] + A[2] + A[3]) );
    }
    else if ( (N >= 1000) && (N < 10000)) {
        A[1] = N % 10; A[2] = (N/10) % 10; A[3] = (N/100) % 10; A[4] = (N/1000) % 10;
        printf ("%d\n", (A[1] + A[2] + A[3] + A[4]) );
    }
    else if ( (N >= 10000) && (N < 100000)) {
        A[1] = N % 10; A[2] = (N/10) % 10; A[3] = (N/100) % 10; A[4] = (N/1000) % 10; A[5] = (N/10000) % 10;
        printf ("%d\n", (A[1] + A[2] + A[3] + A[4] + A[5]) );
    }
    else if ( (N >= 100000) && (N < 1000000)) {
        A[1] = N % 10; A[2] = (N/10) % 10; A[3] = (N/100) % 10; A[4] = (N/1000) % 10; A[5] = (N/10000) % 10; A[6] = (N/100000) % 10;
        printf ("%d\n", (A[1] + A[2] + A[3] + A[4] + A[5] + A[6]) );
    }
    else if ( (N >= 1000000) && (N < 10000000)) {
        A[1] = N % 10; A[2] = (N/10) % 10; A[3] = (N/100) % 10; A[4] = (N/1000) % 10; A[5] = (N/10000) % 10; A[6] = (N/100000) % 10; A[7] = (N/1000000) % 10;
        printf ("%d\n", (A[1] + A[2] + A[3] + A[4] + A[5] + A[6] + A[7]) );
    }
    // int i, A, B[1127];
    // A = N;
    // for (i = 1; i <= 8; i++) {
    // while (A > 0) {
    //     A = A / 10;
    //     B[i] = A % 10;
    // }
}