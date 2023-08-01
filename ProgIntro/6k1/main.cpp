#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    int A[N], B[N], i, j, differentA[N], differentB[N];
    for (i = 0; i < N; i++) cin >> A[i];
    for (i = 0; i < N; i++) cin >> B[i];
    sort(A, A + N);
    sort(B, B + N);
    bool same = true;
    j = 0;
    for (i = 0; i < N; i++) {
        if(A[i] != B[i]) {
            same = false;
            differentA[j] = A[i];
            differentB[j] = B[i];
            j++;
        }
    }
    if (same == true) cout << "yes" << endl;
    else {
        int max, maxA = differentA[0], maxB = differentB[0];
        int k;
        for (k = 0; k < j; k++) {
            if (differentA[k] > maxA) maxA = differentA[k];
            if (differentB[k] > maxB) maxB = differentB[k];
        }
        if (maxA > maxB) max = maxA;
        else max = maxB;
        int min, minA = differentA[0], minB = differentB[0];
        for (k = 0; k < j; k++) {
            if (differentA[k] < minA) minA = differentA[k];
            if (differentB[k] < minB) minB = differentB[k];
        }
        if (minA < minB) min = minA;
        else min = minB;
        cout << "no " << min << " " << max << endl;
    }
    return 0;
}

