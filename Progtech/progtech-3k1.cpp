#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class ChessBoardArray {
    protected:
        int *data;
        unsigned int loc(int i, int j) const /* throw(out_of_range) */ {
            int di = i - base, dj = j - base;
            if (di < 0 || di >= length || dj < 0 || dj >= length || (di%2 == 0 && dj%2 != 0) || (di%2 != 0 && dj%2 == 0)) throw out_of_range("invalid index");
            if (di %2 ==0) {  
                if(length % 2 == 0) return di*(length/2) + dj/2;  
                else return di*(length/2) + dj/2 + di/2; }  
      
            else {  
                if(length % 2 == 0) return di*(length/2) + (dj-1)/2;  
                else return di*(length/2) + (dj-1)/2 + (di + 1)/2;  
            } 
        }
        unsigned base, size, length;
        class Row {
            public:
                Row(ChessBoardArray &a, int i) : cbArray(a), row(i) {}
                int & operator [] (int i) const {
                    return cbArray.select(row, i);
                }
            private:
                ChessBoardArray &cbArray;
                int row;
        };
        
        class ConstRow {
            public:
                ConstRow(const ChessBoardArray &a, int i) : cbArray(a), row(i) {}
                int operator [] (int i) const {
                    return cbArray.select(row, i);
                }
            private:
                const ChessBoardArray &cbArray;
                int row;
        };
        
    public:
        ChessBoardArray(unsigned n = 0, unsigned b = 0) {
            if (n%2 == 0) {
                data = new int[n*n/2];
                size = n*n/2;
            }
            else {
                data = new int[n*n/2 + 1];
                size = n*n/2 + 1;
            }
            base = b; length = n;
            for (unsigned int o = 0; o < size; o++) data[o] = 0;
        }
        ChessBoardArray(const ChessBoardArray &a) {
            data = new int[a.size]; base = a.base; size = a.size; length = a.length;
            for (unsigned int o = 0; o < size; o++) data[o] = a.data[o];
        }
        ~ChessBoardArray() {
            delete [] data;
        }
        ChessBoardArray & operator = (const ChessBoardArray &a) {
            delete [] data;
            base = a.base;
            length = a.length;
            size = a.size;
            data = new int[size];
            for (unsigned int o = 0; o < size; o++) data[o] = a.data[o];
            return *this;
        }
        int & select (int i, int j) {
            return data[loc(i, j)];
        }
        int select (int i, int j) const {
            return data[loc(i, j)];
        }
        const Row operator [] (int i) {
            return Row(*this, i);
        }
        const ConstRow operator [] (int i) const {
            return ConstRow(*this, i);
        }
        friend ostream & operator << (ostream &out, const ChessBoardArray &a) {
            int count = 0, num_rows = 0, zero = 0;
            bool more = true;
            if (a.length % 2 == 0) {
                for (unsigned int o = 0; o < a.size; o++) {
                    if (num_rows % 2 == 0) {
                        if (count != a.length) {
                            out << setw(4) << a.data[o] << setw(4) << zero;
                            count += 2;
                        }
                        if (count == a.length) {
                            out << endl;
                            count = 0;
                            num_rows++;
                        }
                    }
                    else {
                        if (count != a.length) {
                            out << setw(4) << zero << setw(4) << a.data[o];
                            count += 2;
                        }
                        if (count == a.length) {
                            out << endl;
                            count = 0;
                            num_rows++;
                        }
                    }
                }
            }
            else {
                for (unsigned int o = 0; o < a.size; o++) {
                    if (num_rows % 2 == 0) {
                        if ( (count != (a.length - 1)) && (more == true) ) {
                            out << setw(4) << a.data[o] << setw(4) << zero;
                            count += 2;
                        }
                        else if ( (count == (a.length - 1)) && (more == true) ) {
                            out << setw(4) << a.data[o] << endl;
                            num_rows++;
                            count = 0;
                            more = false;
                        }
                    }
                    else {
                        if ( (count != (a.length - 1)) && (more == false) ) {
                            out << setw(4) << zero << setw(4) << a.data[o];
                            count += 2;
                        }
                        if ( (count == (a.length - 1)) && (more == false) ) {
                            out << setw(4) << zero << endl;
                            count = 0;
                            num_rows++;
                            more = true;
                        }
                    }
                }
            }
            return out;
        }
};

// int main() {
//     ChessBoardArray a(4, 0);
//     a[0][0] = 5;
//     a[3][3] = 3;
//     try { a[4][1] = 7; }
//     catch(out_of_range &e) { cout <<"a[2][1] is black" << endl; }
//     try { cout << a[4][0] << endl; }
//     catch(out_of_range &e) { cout << "and so is a[1][2]" << endl; }
//     cout << a;
// }

