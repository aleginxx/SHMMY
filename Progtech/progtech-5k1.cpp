#include <iostream>
#include <string>
using namespace std;

struct node{
    string data;
    int freq;
    node *left, *right;
};

node *help_insert(node* t, const string &s) {
    if (t == nullptr) {
        node *p = new node;
        p->data = s;
        p->freq = 1;
        p->right = p->left = nullptr;
    }
    else if (t->data > s) {
        if (t->left == nullptr) {
            node *p = new node;
            p->data = s;
            p->freq = 1;
            t->left = p;
            p->right = p->left = nullptr;
        } 
        else t->left = help_insert(t->left, s);
    }
    else if (t->data < s) {
        if (t->right == nullptr) {
            node *p = new node;
            p->data = s;
            p->freq = 1;
            t->right = p;
            p->right = p->left = nullptr;
        } 
        else t->right = help_insert(t->right, s);
    }
    else if (t->data == s) t->freq++;
    return t;
}

int help_lookup(node* t, const string &s) {
    if (t == nullptr) return 0;
    else if (t->data == s) return t->freq;
    else if (t->data > s) help_lookup(t->left, s);
    else if (t->data < s) help_lookup(t->right, s);
}

int help_depth(node* t, const string &s, int &niveau) {
    if (t == nullptr) return -1;
    else if (t->data > s) {
        ++niveau;
        help_depth(t->left, s, niveau);
    }
    else if (t->data < s) {
        ++niveau;
        help_depth(t->right, s, niveau);
    }
    else if (t->data == s) {
        ++niveau;
        return niveau;
    }
}

void delete_tree(node* t) {
    if (t == nullptr) return;
    delete_tree(t->left);
    delete_tree(t->right);
    delete t;
}

void inorder(ostream &out, node* t) {
    if (t != nullptr) {
        inorder(out, t->left);
        out << t->data << " " << t->freq << endl;
        inorder(out, t->right);
    }
}

node *find_node(node* t, const string &s) {
    if (t == nullptr) return 0;
    else if (t->data > s) find_node(t->left, s);
    else if (t->data < s) find_node(t->right, s);
    else if (t->data == s) return t;
}

void delete_node(node* t, node* q, const string &s) {
    if (t == nullptr) ;
    else if (t->data > s) {
        q = t;
        delete_node(t->left, q, s);
    }
    else if (t->data < s) {
        q = t;
        delete_node(t->right, q, s);
    }
    else if (t->data == s) {
        node *w ;
        node *k;
        if (t->left!=nullptr && t->right!=nullptr) {
            w = t->left;
            k = t;
            while (w->right != nullptr) {
                k = w;
                w = w->right;
            }
            t->data = w->data;
            t->freq = w->freq;
            if (k != t) k->right = nullptr;
            else k->left = nullptr;
            delete w;
            // w->right = t->right;
            // w->left = t->left;
            // if (q->right == t) q->right = w;
            // else if (q->left == t) q->left = w;
            // if (k!=t) {
            //     k->right == nullptr;
            //     delete t;
            // }
            // else delete t;
        }
        else if (t->left==nullptr && t->right==nullptr) {
            if (q->right == t) {
                q->right = nullptr;
                delete t;
            }
            else if (q->left = t) {
                q->left = nullptr;
                delete t;
            }
        }
        else if (t->left==nullptr && t->right!=nullptr) {
            if (q->right == t) {
                q->right = t->right;
                delete t;
            }
            else if (q->left == t) {
                q->left = t->right;
                delete t;
            }
        }
        else if (t->left!=nullptr && t->right==nullptr) {
            if (q->right == t) {
                q->right = t->left;
                delete t;
            }
            else if (q->left == t) {
                q->left = t->left;
                delete t;
            }
        }
    }
}

class lexicon {
    public:
        lexicon() {
            head = nullptr;
        }
        ~lexicon() {
            delete_tree(head);
        }
        void insert(const string &s) {
            node *p;
            if (head == nullptr) {
                head = new node;
                head->data = s;
                head->freq = 1;
                head->left = head->right = nullptr;
            }
            else {
                p = head;
                help_insert(p, s);
            }
        }
        int lookup(const string &s) const {
            node *p = head;
            return help_lookup(p, s);
        }
        int depth(const string &s) const {
            int level = -1;
            node *p = head;
            return help_depth(p, s, level);
        }
        void replace(const string &s1, const string &s2) {
            node *p = head, *q;
            int freq1 = lookup(s1), freq2 = lookup(s2);
            if (freq1 == 0) ;
            else if (freq2 == 0) {
                p = head;
                if (head->data != s1) {
                    q = p;
                    if (p->data > s1) p = p->left;
                    else p = p->right;
                    delete_node(p, q, s1);
                    insert(s2);
                    q = head;
                    node *r = find_node(q, s2);
                    r->freq = freq1;
                }
                else {
                    if (head->left!=nullptr && head->right!=nullptr) {
                        node *w, *k;
                        k = head;
                        w = head->left;
                        while (w->right != nullptr) {
                            k = w;
                            w = w->right;
                        }
                        head->data = w->data;
                        head->freq = w->freq;
                        if (k == p) k->left = nullptr;
                        else k->right = nullptr;
                    }
                    else if (head->left==nullptr && head->right!=nullptr) {
                        head = head->right;
                        delete p;
                    }
                    else if (head->left!=nullptr && head->right==nullptr) {
                        head = head->left;
                        delete p;
                    }
                    else {
                        delete p;
                        head = nullptr;
                    }
                    insert(s2);
                    q = head;
                    node *r = find_node(q, s2);
                    r->freq = freq1;
                }
            }
            else if (freq2 != 0) {
                p = head;
                node *r = find_node(p, s2);
                r->freq += freq1;
                p = head;
                if (head->data != s1) {
                    q = p;
                    if (p->data > s1) p = p->left;
                    else p = p->right;
                    delete_node(p, q, s1);
                }
                else {
                    if (head->left!=nullptr && head->right!=nullptr) {
                        node *w, *k;
                        k = head;
                        w = head->left;
                        while (w->right != nullptr) {
                            k = w;
                            w = w->right;
                        }
                        head->data = w->data;
                        head->freq = w->freq;
                        if (k == p) k->left = nullptr;
                        else k->right = nullptr;
                    }
                    else if (head->left==nullptr && head->right!=nullptr) {
                        head = head->right;
                        delete p;
                    }
                    else if (head->left!=nullptr && head->right==nullptr) {
                        head = head->left;
                        delete p;
                    }
                    else {
                        delete p;
                        head = nullptr;
                    }
                }
            }
        }
        friend ostream & operator << (ostream &out, const lexicon &l) {
            node *p = l.head;
            inorder(out, p);
            return out;
        }
    private:
        node *head;
};

// int main() {
//     lexicon l;
//     l.insert("the");
//     l.insert("boy");
//     l.insert("and");
//     l.insert("the");
//     l.insert("wolf");
//     cout << l;
//     cout << "The word 'and' is found " << l.lookup("and") << " time(s) at depth" << l.depth("and") << endl;
//     cout << "The word 'boy' is found " << l.lookup("boy") << " time(s) at depth" << l.depth("boy") << endl;    
//     cout << "The word 'the' is found " << l.lookup("the") << " time(s) at depth" << l.depth("the") << endl;
//     cout << "The word 'the' is found " << l.lookup("the") << " time(s) at depth" << l.depth("the") << endl;
//     cout << "The word 'wolf' is found " << l.lookup("wolf") << " time(s) at depth" << l.depth("wolf") << endl;
//     cout << "The word 'dummy' is found " << l.lookup("dummy") << " time(s) at depth" << l.depth("dummy") << endl;
//     l.replace("and", "dummy");
//     cout << "After replacement:" << endl;
//     cout << "Now the word 'wolf' is found "  << l.lookup("wolf") << " time(s) at depth " << l.depth("wolf") << endl;
//     cout << "Now the word 'dummy' is found " << l.lookup("dummy") << " times(s) at depth "<< l.depth("dummy") << endl;
//     cout << l;
//     l.replace("boy", "dummy");
//     cout << "After replacement:" << endl;
//     cout << "Now the word 'wolf' is found "  << l.lookup("wolf") << " time(s) at depth " << l.depth("wolf") << endl;
//     cout << "Now the word 'dummy' is found " << l.lookup("dummy") << " times(s) at depth "<< l.depth("dummy") << endl;
//     cout << l;
//     l.replace("the", "dummy");
//     cout << "After replacement:" << endl;
//     cout << "Now the word 'wolf' is found "  << l.lookup("wolf") << " time(s) at depth " << l.depth("wolf") << endl;
//     cout << "Now the word 'dummy' is found " << l.lookup("dummy") << " times(s) at depth "<< l.depth("dummy") << endl;
//     cout << l;
//     l.replace("wolf", "dummy");
//     cout << "After replacement:" << endl;
//     cout << "Now the word 'wolf' is found "  << l.lookup("wolf") << " time(s) at depth " << l.depth("wolf") << endl;
//     cout << "Now the word 'dummy' is found " << l.lookup("dummy") << " times(s) at depth "<< l.depth("dummy") << endl;
//     cout << l;
// }

