#include <iostream>
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





