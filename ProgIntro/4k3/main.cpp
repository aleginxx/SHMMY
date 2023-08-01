#include <iostream>
using namespace std;
int main() {
    int N, M;
    cin >> N;  cin >> M;
    int A[N][M], B[M], C[N];
    int i, j, max, min;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) 
            cin >> A[i][j];
    }
    for (j = 0; j < M; j++) {
        B[j] = A[0][j];
        for (i = 1; i < N; i++)
            if (A[i][j] > B[j]) B[j] = A[i][j];
    }
    min = B[0];
    for (j = 0; j < M; j++) {
        if (B[j] < min) min = B[j];
    }
    cout << min << endl;
    
    for (i = 0; i < N; i++) {
        C[i] = A[i][0];
        for (j = 1; j < M; j++)
            if (A[i][j] < C[i]) C[i] = A[i][j];
    }
    if (C[0]!= 0) max = C[0];
    else max = C[1];
    for (i = 0; i < N; i++) {
        if (C[i] > max) max = C[i];
    }
    cout << max << endl;
}


