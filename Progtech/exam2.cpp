#include <iostream>
#include <list>
#include <vector>
#include <bits/stdc++.h>
#include<numeric>
using namespace std;

class Graph {
    private:
        list<int> *l;
        int *p;
        int num_nodes, length, detect, numero;
        bool now_break;
        enum state {visited, unvisited, seen};
        
    public:
        Graph(int V) {
            num_nodes = V; 
            l = new list<int>[num_nodes];
            p = new int[num_nodes];
            length = 0;
            now_break = false;
            detect = -1;
        }
        ~Graph() {
            delete [] l;
        }
        void addValue(int i, int val) {
            p[i] = val;
        }
        void addEdge(int u, int v) {
            l[u].push_back(v);
        }
        void triangle_help(int u, vector<state> &status, int &numero, vector<int>* &reverse_path) {
            vector<int> check;
            if (status[u] == unvisited) {
                status[u] = visited;
                list<int>::iterator it1, it2, it3;
                for (it1 = l[u].begin(); it1 != l[u].end(); ++it1) {
                    for (it2 = l[u].begin(); it2 != l[u].end(); ++it2) {
                        for (it3 = l[u].begin(); it3 != l[u].end(); ++it3) {
                            if (*it1 == *it3) {
                                if (numero == 0) {
                                    reverse_path[numero].push_back(*it1); reverse_path[numero].push_back(*it2); reverse_path[numero].push_back(*it3);
                                    ++numero;
                                }
                                else {
                                    check.push_back(*it1); check.push_back(*it2); check.push_back(*it3); 
                                    bool same = false;
                                    sort(check.begin(), check.end());
                                    for (int h = 0; h < numero; ++h) {
                                        sort(reverse_path[h].begin(), reverse_path[h].end());
                                        if (reverse_path[h] == check) same = true;
                                    }
                                    if (same == false) {
                                        reverse_path[numero].push_back(*it1); reverse_path[numero].push_back(*it2); reverse_path[numero].push_back(*it3);
                                        ++numero;
                                    }
                                }
                            }
                        }
                    } 
                }
            }
        }
        void triangle(vector<int>* &reverse_path, int &numero) {
            vector<state> status(num_nodes);

            for (int i = 0; i < num_nodes; i++) {
                status[i] = unvisited;
            }
            for (int i = 0; i < num_nodes; ++i) {
                now_break = false; 
                length = 0;
                detect = -1;
                numero = 0;
                triangle_help(i, status, numero, reverse_path);
            }
        }
        int giveTriangles(int Uu, int L) {
            vector<int> *reverse_path = new vector<int>[num_nodes];
            numero = 0; 
            int new_num = 0, sum = 0;
            triangle(reverse_path, numero);
            for(unsigned int i = 0; i < numero; i++) {
                for (int j = 0; j < 3; ++j) sum += p[i];
                if ((sum >= L) && (sum <= Uu)) new_num++;
            }
            return new_num;
        }
};

int main() {
    int N, M, L, Uu;
    cin >> N >> M >> L >> Uu;
    int val = 0;
    Graph g(N);
    for (unsigned int i = 0; i < N; i++) {
        cin >> val;
        g.addValue(i, val);
    }
    int U, V;
    for (unsigned int i = 0; i < M; i++) {
        cin >> U >> V;
        g.addEdge(U, V);
    }
    cout << g.giveTriangles(Uu, L);
    
}