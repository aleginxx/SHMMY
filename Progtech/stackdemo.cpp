#include <iostream>
using namespace std;

template <typename T>
class stack {
    public:
        stack(int size) {
        random = size;
        top = 0;
        p = new T[size];
    }
    stack(const stack &s) {
        top = s.top;
        random = s.random;
        p = new T[random];
        for (int i = 0; i < top; i++) p[i] = s.p[i];
    }
    ~stack() {
        delete [] p;
    }
    const stack & operator=(const stack &s) {
        delete [] p;
        top = s.top;
        random = s.random;
        p = new T[random];
        for (int h = 0; h < top; h++) p[h] = s.p[h];
    }
    bool empty() {
        return top == 0;
    }
    void push(const T &x) {
        p[top++] = x;
    }
    T pop() {
        return p[--top];
    }
    int size() {
        return niveau = top;
    }
    friend ostream& operator<<(std::ostream& out, const stack &s) {
        if (s.top == 0) cout << "[]" ;
        else {
            out << "[" ;
            for (int j = 0; j < s.top - 1; j++) out << s.p[j] << ", ";
            out << s.p[s.top - 1] << "]";
        }
        return out;
    }
    private:
        int top, niveau, random;
        T *p;
};