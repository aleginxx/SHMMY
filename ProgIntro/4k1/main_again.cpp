#include <math.h>
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int A1[10], A2[10], A3[10], A4[10], A5[10], A6[10], A7[10], A8[10];
    int a, b, c, d, e, f, g, h;
    for (a = 0; a < 10; a++) A8[a] = pow(a, N);
    for (b = 0; b < 10; b++) A7[b] = pow(b, N);
    for (c = 0; c < 10; c++) A6[c] = pow(c, N);
    for (d = 0; d < 10; d++) A5[d] = pow(d, N);
    for (e = 0; e < 10; e++) A4[e] = pow(e, N);
    for (f = 0; f < 10; f++) A3[f] = pow(f, N);
    for (g = 0; g < 10; g++) A2[g] = pow(g, N);
    for (h = 0; h < 10; h++) A1[h] = pow(h, N);
    
    for (a = 0; a < 10; a++) { 
        for (b = 0; b < 10; b++) {
            for (c = 0; c < 10; c++) {
                for(d = 0; d < 10; d++) {
                    for (e = 0; e < 10; e++) {
                        for (f = 0; f < 10; f++) {
                            for (g = 0; g < 10; g++) {
                                for (h = 0; h < 10; h++) {
                                    if (A8[a] + A7[b] + A6[c] + A5[d] + A4[e] + A3[f] + A2[g] + A1[h] == a*10000000 + b*1000000 + c*100000 + d*10000 + e*1000 + f*100 + g*10 + h*1)
                                    cout <<  a*10000000 + b*1000000 + c*100000 + d*10000 + e*1000 + f*100 + g*10 + h*1 << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}