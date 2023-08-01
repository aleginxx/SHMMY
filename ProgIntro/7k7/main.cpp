#include <iostream>
using namespace std;
int gcd(int a, int b) {
    int c;
    while ((a != 0) && (b != 0)) {
    if (abs(a) > abs(b)) a %= b;
    else b %= a;
    }
    return c = a + b;
}

int main() {
    int N, i, count, divider, n, k;
    cin >> N;
    count = 0;
    for (i = 2; i <= N; i++) {
        divider = 0;
        n = N, k = i;
        divider = gcd(n, k); 
        if (divider > 1) count++;
    }
    cout << count << endl;
}