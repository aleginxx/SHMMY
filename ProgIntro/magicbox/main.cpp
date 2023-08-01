#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n <= 2 || n >19) {
        cout << "error" << endl;
        cout << "if you want to retry press 1" << endl;
        int retry; cin >> retry;
        if (retry == 1) main();
    }
    else if (n % 2 == 0) {
        cout << "error" << endl;
        cout << "if you want to retry press 1" << endl;
        int retry; cin >> retry;
        if (retry == 1) main();
    }
    else {
        int a[n][n], i, j, k, h, m;
        i = n / 2; j = n; k = 0;
        for (h = 1; h <= n; h++) {
            j--;
            a[i][j] = k; 
            k++;
            for (m = 2; m <= n; m++) {
                j = (j + 1) % n; i = (i + 1) % n;
                a[i][j] = k; 
                k++;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; i++) {
                cout << a[i][j]; 
                cout << " " ;
            }
        }
    }
}