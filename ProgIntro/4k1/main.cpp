#include <math.h>
#include <iostream>
using namespace std;
    int N;
    bool fact = false;
    int count, i;
    
int digit1() {
        for (i = 0; i < 10; i++) {
        fact = false;
        if ( pow(i,N) == i) fact = true;
        if (fact == true) cout << i << endl;
    }
}
int digits2() {
    for (i = 10; i < 100; i++) {
        fact = false;
        if ( pow(i%10, N) + pow((i/10)%10, N) == i) fact = true;
        if (fact == true) cout << i << endl;
    }
}
int digits3() {
    for (i = 100; i < 1000; i++) {
        fact = false;
        if ( pow(i%10, N) + pow((i/10)%10, N) + pow((i/100)%10, N) == i) fact = true;
        if (fact == true) cout << i << endl;
    }
}
int digits4() {
    for (i = 1000; i < 10000; i++) {
        fact = false;
        if ( pow(i%10, N) + pow((i/10)%10, N) + pow((i/100)%10, N) + pow((i/1000)%10, N) == i) fact = true;
        if (fact == true) cout << i << endl;
    }
}
int digits5() {
    for (i = 10000; i < 100000; i++) {
        fact = false;
        if ( pow(i%10, N) + pow((i/10)%10, N) + pow((i/100)%10, N) + pow((i/1000)%10, N) + pow((i/10000)%10, N) == i) fact = true;
        if (fact == true) cout << i << endl;
    }
}
int digits6() {
    for (i = 100000; i < 1000000; i++) {
        fact = false;
        if ( pow(i%10, N) + pow((i/10)%10, N) + pow((i/100)%10, N) + pow((i/1000)%10, N) + pow((i/10000)%10, N) + pow((i/100000)%10, N) == i) fact = true;
        if (fact == true) cout << i << endl;
    }
}
int digits7() {
    for (i = 1000000; i < 10000000; i++) {
        fact = false;
        if ( pow(i%10, N) + pow((i/10)%10, N) + pow((i/100)%10, N) + pow((i/1000)%10, N) + pow((i/10000)%10, N) + pow((i/100000)%10, N) + pow((i/1000000)%10, N) == i) fact = true;
        if (fact == true) cout << i << endl;
    }
}
int digits8() {
    for (i = 10000000; i < 100000000; i++) {
        fact = false;
        if ( pow(i%10, N) + pow((i/10)%10, N) + pow((i/100)%10, N) + pow((i/1000)%10, N) + pow((i/10000)%10, N) + pow((i/100000)%10, N) + pow((i/1000000)%10, N) + pow((i/10000000)%10, N) == i) fact = true;
        if (fact == true) cout << i << endl;
    }   
}

int main() {
    cin >> N;
    if ( N == 1) {
        digit1();
    }
    else if (N == 2) {
        digit1();
    }
    else if (N == 3) {
        digit1();
        digits2();
        digits3();
    }
    else if (N == 4) {
        digit1();
        digits4();
    }
    else if (N == 5) {
        digit1();
        digits4();
        digits5();
        digits6();
    }
    else if (N == 6) {
        digit1();
        digits6();
    }
    else if (N == 7) {
        digit1();
        digits7();
        digits8();
    }
    else if (N == 8) {
        digit1();
        digits8();
    }
    else if (N == 9) {
        digit1();
    }
}