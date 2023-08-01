#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class Move{
    public:
        Move(int sh, int sc, int th, int tc);
        int getSource() const;
        int getSourceCoins() const;
        int getTarget() const;
        int getTargetCoins() const;
        friend ostream & operator << (ostream &out, const Move &move);
    private:
        int a, b, c, d;
};

Move::Move(int sh, int sc, int th, int tc) {
    a = sh; b = sc; c = th; d = tc;
}
int Move::getSource() const {
    return a;
}
int Move::getSourceCoins() const {
    return b;
}
int Move::getTarget() const {
    return c;
}
int Move::getTargetCoins() const {
    return d;
}
ostream & operator << (ostream &out, const Move &move) {
    if (move.getTargetCoins() != 0) 
    return out << "takes " << move.getSourceCoins() << " coins from heap " << move.getSource() << " and puts " << move.getTargetCoins() << " coins to heap " << move.getTarget();
    else return out << "takes " << move.getSourceCoins() << " coins from heap " << move.getSource() << " and puts nothing";
}


class State {
    public:
        State(int h, const int c[], int n) {
            p = h;
            play = n;
            playing = 0;
            array = new int[h];
            for (int kappa = 0; kappa < p; kappa++) {
                array[kappa] = c[kappa];
            }
        }
        ~State() {
            delete [] array;
        }
        void next(const Move &move) {
            i = move.getSource(); j = move.getTarget();
            k = move.getSourceCoins();
            m = move.getTargetCoins();
            if (i >= p || i < 0 || j >= p || j < 0) throw logic_error("invalid heap");
            if (k < 0 || k > array[i] || m < 0 || m >= k) throw logic_error("invalid coins");
            array[i] -= k;
            array[j] += m;
            if (playing == (play - 1) ) playing = 0;
            else playing++;
        }
        bool winning() const {
            bool win = true;
            for (int l = 0; l < p; l++) {
                if (array[l] != 0) win = false;
            }
            if (win == true) return true;
            else return false;
        }
        int getHeaps() const {
            return p;
        }
        int getCoins(int h) const {
            if (array[h] < 0) throw logic_error("invalid coins");
            if (h >= p || h < 0) throw logic_error("invalid heaps");
            return array[h];
        }
        int getPlayers() const {
            return play;
        }
        int getPlaying() const {
            return playing;
        }
        friend ostream & operator << (ostream &out, const State &state) {
            for (int a = 0; a < (state.getHeaps() - 1); a++) {
                out << state.getCoins(a) << ", " ;
            }
            return out << state.getCoins(state.getHeaps() - 1) << " with " << state.getPlaying() << "/" << state.getPlayers() << " playing next";
        }
    private:
        int i, j, k, m, p, play, playing;
        int *array;
};

int findingMaxHeap (const State &state) {
    int AllHeaps = state.getHeaps(), max = state.getCoins(0), maxHeap = 0 ;
    for (unsigned int l = 0; l < AllHeaps; l++) {
        if (state.getCoins(l) > max) {
            max = state.getCoins(l);
            maxHeap = l;
        }
    }
    return maxHeap;
}

int findingMinHeap (const State &s) {
    int AllHeaps = s.getHeaps(), min = s.getCoins(0), minHeap = 0;
    for (unsigned int l = 0; l < AllHeaps; l++) {
        if (s.getCoins(l) < min) {
            min = s.getCoins(l);
            minHeap = l;
        }
    }
    return minHeap;
}
int refindingMinHeap (const State &s) {    
    int AllHeaps = s.getHeaps(), min = 10000, minHeap = 0;
    for (unsigned int l = 0; l < AllHeaps; l++) {
        if (s.getCoins(l) < min && s.getCoins(l) > 0) {
            min = s.getCoins(l);
            minHeap = l;
        }
    }
    return minHeap;
}


class Player {
    public:
        Player(const string &n) : name(n) {}
        virtual ~Player() {}
        virtual const string &getType() const = 0;
        virtual Move play(const State &s) = 0;
        friend ostream & operator << (ostream &out, const Player &player) {
            return out << player.getType() << " player " << player.name ;
        }
    protected:
        string name;
        string type;
};

class GreedyPlayer : public Player {
    public:
        GreedyPlayer(const string &n) : Player(n) {
            type = "Greedy";
        }
        ~GreedyPlayer() {}
        const string &getType() const override {
            return type;
        }
        Move play(const State &s) override {
            max = findingMaxHeap(s);
            maxCoins = s.getCoins(max);
            return Move(max, maxCoins, 0, 0);
        }
    private:
        int max, maxCoins;
};

class SpartanPlayer : public Player {
    public: 
        SpartanPlayer(const string &n) : Player(n) {
            type = "Spartan";
        }
        ~SpartanPlayer() {}
        const string &getType() const override {
            return type;
        }
        Move play(const State &s) {
            max = findingMaxHeap(s);
            return Move(max, 1, 0, 0);
        }
    private:
        int max;
};

class SneakyPlayer : public Player {
    public:
        SneakyPlayer(const string &n) : Player(n) {
            type = "Sneaky";
        }
        ~SneakyPlayer() {}
        const string &getType() const override {
            return type;
        }
        Move play(const State &s) {
            min = refindingMinHeap(s);
            minCoins = s.getCoins(min);
            return Move(min, minCoins, 0, 0);
        }
    private:
        int min, minCoins;
};

class RighteousPlayer : public Player {
    public:
        RighteousPlayer(const string &n) : Player(n) {
            type = "Righteous";
        }
        ~RighteousPlayer() {}
        const string &getType() const override {
            return type;
        }
        Move play(const State &s) {
            max = findingMaxHeap(s);
            min = findingMinHeap(s);
            c = s.getCoins(max);
            return Move(max, c/2, min, c/2 - 1);
        }
    private:
        int max, min, c;
};

class Game {
    public:
        Game(int heaps, int players) {
            num_heaps = heaps;
            current_heaps = 0;
            num_players = players;
            current_players = 0;
            pinakas_heap = new int[num_heaps];
            pinakas_player = new Player*[num_players];
        }
        ~Game() {
            delete [] pinakas_heap;
            delete [] pinakas_player;
        }
        void addHeap(int coins) { // throw logic error //  
            if (current_heaps == num_heaps || coins < 0) throw logic_error("invalid heaps");
            pinakas_heap[current_heaps++] = coins;
        }
        void addPlayer(Player *player) { //throw logic error //
            if (current_players == num_players) throw logic_error("invalid players");
            pinakas_player[current_players++] = player;
        }
        void play(ostream &out) { //throw logic error//
            State s(num_heaps, pinakas_heap, num_players);
            int l = 0;
            if (current_players != num_players || current_heaps != num_heaps) throw logic_error("cannot start the game");
            while (s.winning() == false) {
                out << "State: " << s << endl;
                out << *pinakas_player[l] << " ";
                out << pinakas_player[l] -> play(s) << endl;
                s.next(pinakas_player[l] -> play(s));
                if (l == num_players - 1) l = 0;
                else l++;
            }
            out << "State: " << s << endl;
            if (l != 0) out << *pinakas_player[--l] << " wins" << endl;
            else out << *pinakas_player[num_players - 1] << " wins" << endl;
        }
        int getPlayers() const {
            return num_players;
        }
        const Player* getPlayer(int p) const { //throw logic error//
            if (p < 0 || p >= num_players) throw logic_error("invalid player");
            return pinakas_player[p];
        }
    private:
        int num_heaps, num_players, *pinakas_heap, current_heaps, current_players;
        Player **pinakas_player;
};
