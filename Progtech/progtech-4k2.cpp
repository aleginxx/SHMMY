#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    private:
        list<int> *l;
        int num_nodes, length, detect;
        bool now_break;
        enum state {visited, unvisited, seen};
        
    public:
        Graph(int V) {
            num_nodes = V; 
            l = new list<int>[num_nodes];
            length = 0;
            now_break = false;
            detect = -1;
        }
        ~Graph() {
            delete [] l;
        }
        void addEdge(int u, int v) {
            l[u].push_back(v);
        }
        bool cycle_help(int u, vector<state> &status, vector<bool> &in_stack, vector<int> &reverse_path) {
            if (status[u] == unvisited) {
                status[u] = visited;
                in_stack[u] = true;
                list<int>::iterator it;
                for (it = l[u].begin(); it != l[u].end(); ++it) {
                    if ((status[*it] == unvisited) && (cycle_help(*it, status, in_stack, reverse_path))) {
                        if (detect == *it) now_break = true;
                        if (now_break == true) return true;
                        reverse_path.push_back(*it);
                        ++length;
                        return true;
                    }
                    else if (in_stack[*it] && status[*it] == visited) {
                        reverse_path.push_back(*it);
                        ++length;
                        detect = *it;
                        return true;
                    }
                }
            }
            in_stack[u] = false;
            return false;
        }
        bool cycle(vector<int> &path) {
            vector<state> status(num_nodes);
            vector<bool> in_stack(num_nodes);
            vector<int> reverse_path;
            
            for (int i = 0; i < num_nodes; i++) {
                status[i] = unvisited;
                in_stack[i] = false;
            }
            for (int i = 0; i < num_nodes; ++i) {
                now_break = false; 
                length = 0;
                detect = -1;
                if (cycle_help(i, status, in_stack, reverse_path)) {
                    for (int j = (length - 1); j >= 0; --j) path.push_back(reverse_path[j]);
                    return true;
                }
                else reverse_path.clear();
            }
            return false;
        }
};

// int main() {
//     int V, E;
//     cin >> V >> E;
//     Graph g(V);
//     for (int i = 0; i < E; ++i) { int u, v; cin >> u >> v; g.addEdge(u, v); }
//     vector<int> path;
//     bool c = g.cycle(path);
//     if (c) {
//     cout << "CYCLE: " ;
//     for (int i = 0; i < path.size() - 1; ++i)
//     cout << path[i] << " ";
//     cout << path[path.size() - 1] << endl;
//     } 
//     else {
//     cout << "NO CYCLE" << endl;
//     }
// }

