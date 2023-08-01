#include <iostream>
using namespace std;

int main() {
    int N, length[1000], j, count = 0;
    double percent;
    char end;
    bool isPalindrome;
    string inputs[1000];
    cin >> N; 
    end = getchar();
    
    for (j = 0; j < N; j++) {
        inputs[j] = "";
        getline(cin, inputs[j]);
        length[j] = inputs[j].length();
        // cout << length[j] << endl;
    }
    
    for (j = 0; j < N; j++) {    
        if (length[j] == 0) {
            cout << "empty" << endl;
            continue;
        }
        else if (length[j] > 20) {
            cout << "error" << endl;
            continue;
        }
        else {
            isPalindrome = true;
            for (int i = 0; i <= ( (length[j] -1)/2); i++) {
                if (inputs[j][i] != inputs[j][(length[j] - 1) - i])
                    isPalindrome = false;
            }
            if (isPalindrome == true) {
                cout << "yes" << endl;
                count++;
            }
            else
                cout << "no" << endl;
        }
    }
    
    percent = count / (float)N;
    percent *= 100;
    printf ("%0.3lf\n", percent);
}