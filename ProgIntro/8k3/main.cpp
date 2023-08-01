#include <cstdio>
using namespace std;
class list {
    public: 
        list();
        bool empty();
        int size();
        void add(int k, int x);
        int get(int k);
        void rmove(int k);
        int searchMF(int x);
    private:
        int length = 0;
        struct node {
            int info;
            node *next;
        };
        node *front, *rear;
};
list::list() {
    front = rear = nullptr;
}
bool list::empty() {
    return front == nullptr;
}
int list::size() {
    return length;
}
void list::add(int k, int x) {
    node *p, *q;
    p = new node;
    p -> info = x;
    if (front == nullptr) {
        front = p;
        front -> next = nullptr;
        length++;
    }
    else if (k == 1) {
        p -> next = front;
        front = p;
        length++;
    }
    else { 
        q = front;
        for (int i = 1; i < (k - 1); i++) q = q -> next;
        p -> next = q -> next;
        q -> next = p;
        length++;
    }
}
int list::get(int k) {
    node *q;
    q = front;
    if (k == 1) return front -> info;
    else {
        for (int i = 0; i < (k - 1); i++) q = q -> next;
        return q -> info;
    }
}
void list::rmove(int k) {
    node *q, *p;
    q = front;
    if (k == 1) {
        front = front -> next;
        delete q;
        length--;
    }
    else {
        for (int i = 1; i < (k - 1); i++) q = q -> next;
        p = q -> next;
        q -> next = p -> next;
        delete p;
        length--;
    }
}
int list::searchMF(int x) {
    node *q, *p;
    bool found = false;
    int count = 1;
    q = front;
    while (q != nullptr) {
        if (q -> info == x) {
            found = true;
            break;
        }
        else {
            p = q;
            q = q -> next;
            count++;
        }
    }
    if (found == true) {
        p -> next = q -> next;
        if (count != 1) {
            q -> next = front;
            front = q;
        }
        return count;
    }
    else return 0;
    
}
int main() {
    int N, K, X, M, G;
    scanf("%d", &N);
    int i, j, y = 0;
    list s;
    for (i = 0; i < N; i++) {
        scanf("%d", &K); scanf("%d", &X);
        s.add(K, X);
    }
    scanf("%d", &M);
    for (j = 0; j < M; j++) {
        scanf("%d", &X);
        y += s.searchMF(X);
    } 
    printf("%d\n", y);
}