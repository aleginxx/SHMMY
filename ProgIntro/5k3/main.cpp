#include <iostream>
#include <ctype.h>
using namespace std;
int main() {
    char A[27], character1;
    int i1, count1 = 0;
    character1 = getchar();
    while (character1 != '\n') {
            A[count1] = character1;
            if (isdigit(A[count1])) {
                cout << "error" << endl;
                return 0;
            }
            count1++;
            character1 = getchar();
            if (count1 > 26) {
                cout << "error" << endl;
                return 0;
            }
    }
    if (count1 < 26) {
        cout << "error" << endl;
        return 0;
    }
    for (count1 = 0; count1 < 25; count1++) {
        for (int i1 = (count1 + 1); i1 < 26; i1++) {
            if (A[count1] == A[i1]) {
                cout << "error" << endl;
                return 0;
            }
        }
    }
    char c[8];
    for (int l = 0; l < 8; l++) {
        c[l] = getchar();
        if (c[l] == '\n') break;
    }
    if (c[0] == 'e') {
        char k = 'a', B[52], K = 'A';
        for (count1 = 0; count1 < 26; count1++) {
            B[count1] = k;
            k++;
        }
        for (count1 = 26; count1 < 52; count1++) {
            B[count1] = K;
            K++;
        }
        int count2 = 0;
        char character2 = getchar();
        while (character2 != EOF) {
            if (ispunct(character2) || isdigit(character2) || isspace(character2) || (character2 == '\n')) {
                cout << character2;
            }
            else if ( (character2 >= 'a') && (character2 <= 'z') ) {
                for (count1 = 0; count1 < 26; count1++) {
                    if (character2 == B[count1]) {
                        character2 = A[count1];
                        cout << character2;
                        break;
                    }
                }
            }
            else if ( (character2 >= 'A') && (character2 <= 'Z')) {
                for (count1 = 26; count1 < 52; count1++) {
                    if (character2 == B[count1]) {
                        character2 = toupper(A[count1 - 26]);
                        cout << character2;
                        break;
                    }
                }
            }
            character2 = getchar();
        }
    }
    else if (c[0] == 'd') {
        char k = 'a', B[52], K = 'A';
        for (count1 = 0; count1 < 26; count1++) {
            B[count1] = k;
            k++;
        }
        for (count1 = 26; count1 < 52; count1++) {
            B[count1] = K;
            K++;
        }
        int count2 = 0;
        char character2 = getchar();
        while (character2 != EOF) {
            if (ispunct(character2) || isdigit(character2) || isspace(character2) || (character2 == '\n')) {
                cout << character2;
            }
            else if ( (character2 >= 'a') && (character2 <= 'z') ) {
                for (count1 = 0; count1 < 26; count1++) {
                    if (character2 == A[count1]) {
                        character2 = B[count1];
                        cout << character2;
                        break;
                    }
                }
            }
            else if ( (character2 >= 'A') && (character2 <= 'Z')) {
                for (count1 = 26; count1 < 52; count1++) {
                    if (character2 == toupper(A[count1 - 26])) {
                        character2 = B[count1];
                        cout << character2;
                        break;
                    }
                }
            }
            character2 = getchar();
        }
    }
    else {
        cout << "error" << endl;
        return 0;
    }
}
