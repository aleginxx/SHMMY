#include <iostream>
#include <list>
#include <vector>
#include <utility>
using namespace std;

class Graph {
    private:
        list<pair<int, int>> *adj;
        int num_nodes, length, detect, refills;
        int starting_point, destination, gas_given;
        bool now_break;
        enum state {visited, unvisited, seen};
        
    public:
        Graph(int V) {
            num_nodes = V; 
            adj = new list<pair<int,int>>[num_nodes];
            length = 0;
            now_break = false;
            refills = 0;
            detect = -1;
        }
        ~Graph() {
            delete [] adj;
        }
        void addEdge(int u, int v, int l) {
            adj[u].push_back(make_pair(l, v));
        }
        bool route_help(int a, int b, int c, vector<state> &status, vector<int> &reverse_path, int &refills) {
            if (a == b) {
                reverse_path.clear();
                return true;
            }
            int gas_left = c;
            list<pair<int,int>>::iterator it;
            for (it = adj[a].begin(); it != adj[a].end(); ++it) {
                if (status[(*it).second] == unvisited && ( (gas_left >= (*it).first) || (c >= (*it).first))) {
                    status[(*it).second] = visited;
                    if (gas_left >= (*it).first) gas_left -= (*it).first;
                    else if (c >=  (*it).first && gas_left < (*it).first) {
                        gas_left = c - (*it).first;
                        ++refills;
                    }
                    ++length;
                    reverse_path.push_back((*it).second);
                }
                if ((*it).second == b) return true;
            }
            return false;
        }
        bool route(vector<int> &path, int a, int b, int c, int &fills) {
            vector<state> status(num_nodes);
            vector<int> reverse_path;
            starting_point = a; destination = b; gas_given = c; refills = fills;
            
            for (int i = 0; i < num_nodes; i++) {
                status[i] = unvisited;
            }
            now_break = false; 
            length = 0;
            detect = -1;
            if (route_help(starting_point, destination, gas_given, status, reverse_path, refills)) {
                for (int j = (length - 1); j >= 0; --j) path.push_back(reverse_path[j]);
                return true;
            }
            else reverse_path.clear();
        return false;
        }
};

int main() {
    int N, M;
    cin >> N; cin >> M;
    Graph g(N);
    int U, V, L;
    for (unsigned int i = 0; i < M; ++i) {
        cin >> U; cin >> V; cin >> L;
        g.addEdge(U, V, L);
    }
    int Q;
    cin >> Q;
    int A, B, C;
    vector<int> path;
    for (unsigned int i = 0; i < Q; ++i) {
        int fills = 0;
        cin >> A; cin >> B; cin >> C;
        if (g.route(path, A, B, C, fills)) {
            cout << "POSSIBLE: " << fills << " fills(s), ";
            for (unsigned int j = 0; j < path.size() - 1; ++j) cout << path[i] << " ";
            cout << path[path.size() - 1] << endl;
        }
        else cout << "IMPOSSIBLE" << endl;
    }
    
}