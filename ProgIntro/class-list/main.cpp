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
    private:
        int length;
        int data[length];
        int top;
};

list::list() {
    top = 0;
}
bool list::empty() {
    return top == 0;
}
int list::size() {
    return length;
}
void list::add(int k, int x) {
    data[k] = x;
}
int list::get(int k) {
    return data[k];
}
void list::rmove(int k) {
    for (int i = k; i < (length - 1); i++) data[i] = data[i + 1];
    length--;
}

int main() {
    list s;
    int N, M, K, G;
    scanf("%d", &N);
    int i, j, y, k;
    for (i = 0; i < N; i++) {
        scanf("%d", &y);
        scanf("%d", &k);
        s.add(k, y);
    }
    scanf("%d", &M);
    for (j = 0; j < M; j++) {
        scanf("%d", &K);
        s.rmove(K);
    }
    scanf("%d", &G);
    printf("%d", s.size());
    printf(" ");
    printf("%d", s.get(G));
}