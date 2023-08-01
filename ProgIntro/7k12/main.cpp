#include <iostream>
using namespace std;
int give_B(double B, double b[], int N, int k, int count, int dcount) {
    int K;
    for (k = 0; k < N; k++) {
      B += b[k];
      if (B >= 0) {
          count++;
        //   cout << B; cout << " "; cout << count << endl;
      }
      else {
          B = 0;
          count = 0;
          dcount++;
      }
      if (dcount == N) {
          cout << "0" << endl;
          break;
      }
      if (count == N) {
          K = k + 2;
          cout << K << endl;
          break;
      }
      if ( (k == (N - 1)) && (count != N) ) give_B(B, b, N, k, count, dcount);
    }
}

int main() {
    int N; cin >> N;
    int k, count = 0, dcount = 0;
    double b[N], city = 0, B = 0;
    for (k = 0; k < N; k++) 
        cin >> b[k];
    city = give_B(B, b, N, k, count, dcount);
}
