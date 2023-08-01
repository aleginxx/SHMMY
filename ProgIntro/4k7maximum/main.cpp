#include <iostream>
using namespace std;

int maximum() {
    int list[20], a, x;
    for (a = 0; a <= 19; a++) {
    cin >> list[a];
    }
    x = list[0];
    for (a = 0; a <= 19; a++) {
    if (list[a] > x) x = list[a];
    }
    cout << x << endl;
}