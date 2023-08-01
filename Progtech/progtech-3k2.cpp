#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {
    protected:
        class Term {
            protected:
                int exponent; /* εκθέτης */ 
                int coefficient; /* συντελεστής */ 
                Term *next;
                Term(int exp, int coeff, Term *n) {
                    exponent  = exp;
                    coefficient = coeff;
                    next = n;
                }
                friend class Polynomial;
                friend Polynomial operator+ (const Polynomial &p, const Polynomial &q);
                friend Polynomial operator* (const Polynomial &p, const Polynomial &q);
                friend ostream & operator << (ostream &out, const Polynomial &q);
        };
        Term *q;
        Term *head;
        
    public:
        Polynomial() {
            head = new Term(0, 0, nullptr);
        }
        Polynomial(const Polynomial &p) {
            Term *t = p.head;
            head = new Term(t->exponent, t->coefficient, nullptr);
            t = t->next;
            Term *w = head;
            while (t != nullptr) {
                q = new Term(t->exponent, t->coefficient, nullptr);
                w->next = q;
                w = w->next;
                t = t->next;
            }
        }
        ~Polynomial() {
            Term *o = head;
            while (o != nullptr) {
                o = head->next;
                delete head;
                head = o;
            }
            delete head;
        }
        Polynomial & operator = (const Polynomial &p) {
            Term *o = head;
            while (o != nullptr) {
                o = head->next;
                delete head;
                head = o;
            }
            delete head;
            Term *t = p.head;
            head = new Term(t->exponent, t->coefficient, nullptr);
            t = t->next;
            Term *w = head;
            while (t != nullptr) {
                q = new Term(t->exponent, t->coefficient, nullptr);
                w->next = q;
                w = w->next;
                t = t->next;
            }
            return *this;
        }
        void addTerm(int expon, int coeff) {
            Term *p = head, *a;
            a = p -> next;
            if (a == nullptr && p->exponent == expon) {
                p->coefficient += coeff;
                if (p->coefficient == 0) p->exponent = 0;
            }
            else if (p->exponent == expon) {
                p->coefficient += coeff;
                if (p->coefficient == 0) {
                    head = head->next;
                    delete p;
                }
            }
            else if (p->exponent < expon) {
                Term *q = new Term(expon, coeff, p);
                head = q;
            }
            else if (p->exponent > expon && a == nullptr) {
                Term *q = new Term(expon, coeff, nullptr);
                p->next = q;
            }
            else {
                while ( a->exponent > expon && a != nullptr) {
                    p = a;
                    a = a->next;
                }
                if (a->exponent < expon) {
                    Term *q = new Term(expon, coeff, nullptr);
                    q->next = a; 
                    p->next = q;
                }
                else {
                    a->coefficient += coeff;
                    if (a->coefficient == 0) {
                        p->next = a->next;
                        delete a;
                    }
                }
            }
        }
        double evaluate(double x) {
            double sum = 0;
            Term *p = head;
            while (p != nullptr) {
                sum += pow(x, p->exponent) * p->coefficient;
                p = p -> next;
            }
            return sum;
        }
        friend Polynomial operator+ (const Polynomial &p, const Polynomial &q) {
            Term *a = q.head;
            Polynomial z(p);
            while (a != nullptr) {
                z.addTerm(a->exponent, a->coefficient);
                a = a->next;
            }
            
            return z;
        }
        friend Polynomial operator* (const Polynomial &p, const Polynomial &q) {
            Term *a = p.head, *b = q.head;
            Polynomial z;
            while (a != nullptr) {
                while (b != nullptr) {
                    z.addTerm(a->exponent + b->exponent, a->coefficient * b->coefficient);
                    b = b->next;
                }
                a = a->next;
                b = q.head;
            }
            return z;
        }
        friend ostream & operator << (ostream &out, const Polynomial &q) {
            /* αν ο εκθέτης είναι 1, πρέπει να εκτυπώνω σκέτο χ, αν ο συντελεστής είναι 1 πρέπει να εκτυπώνω σκέτο το χ με τη δύναμη, αν ο εκθέτης είναι 0 πρέπει να εκτυπώνω
            σκέτο τον συντελεστή και αν ο συντελεστής είναι 0 πρέπει να μην εκτυπώνω καθόλου τον όρο*/
            Term *a = q.head;
            if (a->next == nullptr && a->coefficient == 0) out << "0";
            while (a != nullptr) {
                if (a == q.head) {
                    if (a->coefficient < 0) {
                        if (a->exponent == 0) {
                            if (a->coefficient == -1) out << "- 1";
                            else out << "- " << -a->coefficient;
                        }
                        else if (a->exponent == 1) {
                            if (a->coefficient == -1) out << "- x";
                            else out << "- " << -a->coefficient << "x";
                        }
                        else {
                            if (a->coefficient == -1) out << "- x^" << a->exponent;
                            else out << "- " << -a->coefficient << "x^" << a->exponent;
                        }
                    }
                    else if (a->coefficient > 0) {
                        if (a->exponent == 0) {
                            if (a->coefficient == 1) out << "1" ;
                            else out << a->coefficient;
                        }
                        else if (a->exponent == 1) {
                            if (a->coefficient == 1) out << "x";
                            else out << a->coefficient << "x";
                        }
                        else {
                            if (a->coefficient == 1) out << "x^" << a->exponent;
                            else out << a->coefficient << "x^" << a->exponent;
                        }
                    }
                    else ;
                }
                else {
                    if (a->coefficient < 0) {
                        if (a->exponent == 0) {
                            if (a->coefficient == -1) out << " - 1";
                            else out << " - " << -a->coefficient;
                        }
                        else if (a->exponent == 1) {
                            if (a->coefficient == -1) out << " - x";
                            else out << " - " << -a->coefficient << "x";
                        }
                        else {
                            if (a->coefficient == -1) out << " - x^" << a->exponent;
                            else out << " - " << -a->coefficient << "x^" << a->exponent;
                        }
                    }
                    else if (a->coefficient > 0) {
                        if (a->exponent == 0) {
                            if (a->coefficient == 1) out << " + 1";
                            else out << " + " << a->coefficient;
                        }
                        else if (a->exponent == 1) {
                            if (a->coefficient == 1) out << " + x";
                            else out << " + " << a->coefficient << "x";
                        }
                        else {
                            if (a->coefficient == 1) out << " + x^" << a->exponent;
                            else out << " + " << a->coefficient << "x^" << a->exponent;
                        }
                    }
                    else ;
                }
                a = a->next;
            }
            return out;
        }
};

// int main() {
//     Polynomial p;
//     p.addTerm(1,3);
//     p.addTerm(2,1);
//     p.addTerm(0,-1);
//     cout << "P(x) = " << p << endl;
//     cout << "P(1) = " << p.evaluate(1) << endl;
//     Polynomial q(p);
//     q.addTerm(1, -3);
//     cout << "Q(x) = " << q << endl;
//     cout << "Q(1) = " << q.evaluate(1) << endl;
//     cout << "(P+Q)(x) = " << p+q << endl;
//     cout << "(P*Q)(x) = " << p*q << endl;
// }

