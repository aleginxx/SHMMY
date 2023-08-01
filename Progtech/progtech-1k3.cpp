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


#ifndef CONTEST

int main () {
    // let’s play with integers...
    stack<int> s(10);
    cout << "s is empty: " << s << endl;
    s.push(42);
    cout << "s has one element: " << s << endl;
    s.push(17);
    s.push(34);
    cout << "s has more elements: " << s << endl;
    cout << "How many? " << s.size() << endl;
    stack<int> t(5);
    t.push(7);
    cout << "t: " << t << endl;
    t = s;
    cout << "popping from s: " << s.pop() << endl;
    s.push(8);
    stack<int> a(s);
    t.push(99);
    a.push(77);
    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    cout << "a: " << a << endl;
    // now with doubles...
    stack<double> c(4);
    c.push(3.14);
    c.push(1.414);
    cout << "c contains doubles " << c << endl;
    // and with characters...
    stack<char> k(4);
    k.push('$');
    cout << "k contains a character " << k << endl;
    }
#endif
