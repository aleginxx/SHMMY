#include <cstdio>
#include <iostream>
using namespace std;
int ar1[1127], ar2[1127], par1[1127], par2[1127], AR[1127], PAR[1127], L[1127], i, k;
char symbol[1127];

void p()  {
    if (symbol[i] == '+') {
      if (par1[i] == par2[i]) {
        AR[i] = ar1[i] + ar2[i];
        PAR[i] = par1[i];
        }
        else {
        AR[i] = ar1[i]*par2[i] + ar2[i]*par1[i];
        PAR[i] = par1[i]*par2[i];
        }
    }
    else if (symbol[i] == '-') {
      if (par1[i] == par2[i]) {
        AR[i] = ar1[i] - ar2[i];
        PAR[i] = par1[i];
        }
      else {
      AR[i] = ar1[i]*par2[i] - ar2[i]*par1[i];
      PAR[i] = par1[i]*par2[i];
      }
    }
    else if (symbol[i] == '*') {
      AR[i] = ar1[i]*ar2[i];
      PAR[i] = par1[i]*par2[i];
      ;
    }
    else if (symbol[i] == '/') {
      AR[i] = ar1[i]*par2[i];
      PAR[i] = ar2[i]*par1[i];
      ;
    }
}

void x() {
    while ( ( L[i] != 0) && ( PAR[i] != 0) ) {
        if ( abs(L[i]) > abs(PAR[i]) ) 
            L[i] = L[i] % PAR[i];
        else 
            PAR[i] = PAR[i] % L[i];
        }
    k = abs(L[i] + PAR[i]);
}

int main () {
  int N, A[1127] ,B[1127], C[1127];
  cin >> N;
  for (i=1; i<=N; i++) {
    cin >> symbol[i]; cin >> ar1[i]; cin >> par1[i]; cin >> ar2[i]; cin >> par2[i];
  }
  for (i=1; i<=N; i++) {
    if ( (par1[i] == 0) || (par2[i] == 0) )
      printf ("error\n");
    else if (symbol[i]=='/' && ( (ar1[i]==0) || (ar2[i]==0) ) )
       printf ("error\n");
    else {
      p();
    C[i] = AR[i]/PAR[i];
    L[i] = AR[i]%PAR[i];
    A[i] = L[i]; B[i] = PAR[i];
    x();
    if (C[i]==0 && A[i]==0)
        printf ("%d %d %d\n", C[i], abs(A[i]/k), abs(B[i]/k));
    else if (C[i]==0 && (A[i]*B[i] > 0) ) 
        printf ("%d %d %d\n", C[i], abs(A[i]/k), abs(B[i]/k));
    else if (C[i]==0 && ( (A[i] < 0) || (B[i]<0)) ) 
        {printf ("-0 "); printf ("%d %d\n", abs(A[i]/k), abs(B[i]/k));}
    else 
        printf ("%d %d %d\n", C[i], abs(A[i]/k), abs(B[i]/k));
    }
  }
}
