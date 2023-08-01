#include <iostream>  
using namespace std;  
int main() {  
    int N; cin >> N;  
    int i, j, k = -1, sum = 0, a[N];  
    bool breaking = false;  
    for (i = 0; i < N; i++) cin >> a[i];  
    for (i = 1; i < N; i++) {  
        if (a[i - 1]*a[i] < 0) k = i;  
    }  
    if (k == -1) {  
        if (a[0] < 0) {  
            cout << a[N - 1] + a[N - 2] << endl;  
            return 0;  
        }  
        else {  
            cout << a[0] + a[1] << endl;  
            return 0;  
        }  
    }  
    for (i = 1; i < N; i++) {  
        for (j = 0; j < i; j++) {  
            if (sum == 0) sum = a[j] + a[i];  
            if ( (abs(a[i] + a[j]) > abs(sum)) && ( (a[i] > 0) && (a[j] > 0)) ) {  
                breaking = true;  
                break;  
            }  
            else {  
                if (abs(sum) > abs(a[j] + a[i])) sum = a[j] + a[i];  
            }  
        }  
        if (breaking == true) break;  
    }  
    cout << sum << endl;  
}  