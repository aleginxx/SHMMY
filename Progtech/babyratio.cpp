#ifndef CONTEST
#include <iostream>
#include "babyratio.hpp"
#endif

rational::rational(int n, int d) {
    nom = n; den = d;
}
rational rational::add(rational r) {
    return rational(nom*r.den + r.nom*den, den * r.den);
}
rational rational::sub(rational r) {
    return rational(nom*r.den - r.nom*den, den * r.den);
}
rational rational::mul(rational r) {
    return rational(nom * r.nom, den * r.den);
}
rational rational::div(rational r) {
    return rational(nom * r.den, den * r.nom);
}
void rational::print() {
    int D = gcd(nom, den);
    if (den < 0) std::cout << -nom/D << "/" << -den/D;
    else std::cout << nom/D << "/" << den/D;
}
int rational::gcd(int a, int b) {
    while (abs(a) > 0 && abs(b) > 0) {
        if (abs(a) > abs(b)) a %= b;
        else b %= a;
    }
    return (abs(a) + abs(b));
}