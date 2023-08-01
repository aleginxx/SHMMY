#include <iostream>
using namespace std;
int main() {
    int N; cin >> N;
    int A[N][N], i, j;
    bool s = true, different = true;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> A[i][j];
            if (A[i][j] > (N*N - 1)) s = false;
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 1; j < N; j++) {
            if (A[i][j] == A[i][j - 1]) different = false;
        }
    }
    if ( (s == false) || (different == false) ) cout << "no" << endl;
    else {
        int line[N];
        for (i = 0; i < N; i++) {
            line[i] = A[i][0];
            for (j = 1; j < N; j++) line[i] += A[i][j];
        }
        bool sL = true;
        for (i = 1; i < N; i++) {
            if (line[i] != line [i - 1]) sL = false;
        }
    
        int column[N];
        for (j = 0; j < N; j++) {
            column[j] = A[0][j];
            for (i = 1; i < N; i++) column[j] += A[i][j];
        }
        bool sC = true;
        for (j = 1; j < N; j++) {
            if (column[j] != column[j - 1]) sC = false;
        }
        
        int diag1;
        diag1 = A[0][0];
        for (int k = 1; k < N; k++) diag1 += A[k][k];
        int diag2;
        diag2 = A[0][N - 1];
        for (i = 1; i < N; i++) diag2 += A[i][N - i - 1];
        cout << diag2 << endl;
        if ( (sC == true) && (sL == true) && (diag1 == column[0]) && (diag2 == column[0]) ) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}