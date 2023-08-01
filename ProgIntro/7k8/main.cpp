#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int N, count, binary = 0;
    cin >> N;
    count = 0;
    int P[223898], i = 0;
    // for (int a = 0; a < N; a++) {
    //     if (pow(2, a) < N) continue;
    //     else break;
    //     for (int b = 0; b < a; b++) {
    //         if ( (pow(2, a) + pow(3, b)) < N) continue;
    //         else break;
    //         for (int c = 0; c < a; c++) {
    //             if ( (pow(2, a) + pow(3, b) + pow(5, c)) <= N) {
    //                 P[i] = pow(2, a) + pow(3, b) + pow(5, c);
    //                 i++;
    //             }
    //         }
    //     }
    // }
    int *q; 
    q = P;
    for (int k = 0; k < i; k++) {
        while (*q <= P[i]) {
        if (P[k] == *q) binary = 1;
        q = q++;
        }
        if (binary == 0) count++;
    }
    cout << count << endl;
}