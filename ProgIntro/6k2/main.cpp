#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    FILE *fin, *fout ;
    int j, chars = 0, i = 0, count;
    char c[61];
    fout = fopen("out.txt", "wb");
    if ( (fin = fopen("in.txt", "rb")) == nullptr) return 1;
    while ( (c[i] = fgetc(fin)) != EOF) {
        count = 0;
        if (c[i] != '\n') chars++;
        if (chars == 61) {
            if (isalpha(c[59]) && isalpha(c[60])) {
                for (j = 60; j > 0; j--) {
                    if (c[j] == ' ') break;
                    count++;
                }
                putc('\n', fout);
                for (int k = (j + 1); k < 61; k++) putc(c[k], fout);
                i = count - 1;
                chars = count;
            }
            else if (c[60] == ' ') {
                putc('\n', fout);
                chars = 0;
                i = 0;
            }
            else {
                putc('\n', fout);
                putc(c[60], fout);
                i = 1; 
                chars = 1;
            }
        }
        else if ( (chars < 61) && (c[i] == '\n') ) {
          c[i] = ' ';
          putc(c[i], fout);
          i++;
        } 
        else {
            putc(c[i], fout);
            cout << c[i] << " ";
            i++;
        }
    }
    fclose(fin); 
    fclose(fout);
}