#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#include <algorithm>
#endif
using namespace std;

int gcd(int a, int b) {
    while (abs(a) > 0 && abs(b) > 0) {
        if (abs(a) > abs(b)) a %= b;
        else b %= a;
    }
    return (abs(a) + abs(b));
}
rational::rational(int n, int d) {
    nom = n; den = d;
}
rational operator+(const rational &x, const rational &y) {
    return rational(x.nom*y.den + y.nom*x.den, x.den * y.den);
}
rational operator-(const rational &x, const rational &y) {
    return rational(x.nom*y.den - y.nom*x.den, x.den * y.den);
}
rational operator*(const rational &x, const rational &y) {
    return rational(x.nom * y.nom, x.den * y.den);
}
rational operator/(const rational &x, const rational &y) {
    return rational(x.nom * y.den, y.nom * x.den);
}
std::ostream& operator<<(std::ostream& out, const rational &x) {
    int D = gcd(x.nom, x.den);
    if (x.den < 0) out << -x.nom/D << "/" << -x.den/D;
    else out << x.nom/D << "/" << x.den/D;
    return out;
} 