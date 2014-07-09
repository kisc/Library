struct Dice {
    enum FACE { TOP, FRONT, RIGHT, BOTTOM, BACK, LEFT };
    /*
                                           z軸
                                           |
                                           |
                                           |
                                           |
                                          / ------------------/
                                         /                   /|
                                        /                   / |
                                       /        TOP        /  |
                                      /                   /   |
                                     /                   /    |
                                    |-------------------|     |
                                    |                   |RIGHT|
                                    |                   |     |_______________ x軸
                                    |                   |    /
                                    |       FRONT       |   /
                                    |                   |  /
                                    |                   | /
                                    |                   |/
                                    |-------------------|
                                   /
                                  /
                                 /
                                /
                              y軸
    */
    int v[6];
    Dice() {}
    Dice(int top, int front, int right) {
        v[TOP]   = top;    v[BOTTOM] = 7 - top;
        v[FRONT] = front;  v[BACK]   = 7 - front;
        v[RIGHT] = right;  v[LEFT]   = 7 - right;
    }
    bool operator==(const Dice& d) const {
        for (int i = 0; i < 6; i++)
            if (v[i] != d.v[i])
                return false;
        return true;
    }
    // すべて時計回り
    void rollX() { roll(TOP, FRONT, BOTTOM, BACK); }
    void rollY() { roll(TOP, LEFT, BOTTOM, RIGHT); }
    void rollZ() { roll(FRONT, RIGHT, BACK, LEFT); }
    void roll(int a, int b, int c, int d) {
        int t = v[a];
        v[a] = v[b]; v[b] = v[c]; v[c] = v[d]; v[d] = t;
    }
    vector<Dice> allState() const {
        vector<Dice> Ret;
        Dice d = *this;
        for (int i = 0; i < 6; i++) {
            if (i % 2 == 0) d.rollX();
            else            d.rollY();
            for (int j = 0; j < 4; j++) {
                d.rollZ();
                Ret.push_back(d);
            }
        }
        return Ret;
    }
    bool isSameDice(const Dice& d) const {
        vector<Dice> states = allState();
        for (int i = 0; i < states.size(); i++) {
            if (states[i] == d) return true;
        }
        return false;
    }
};
ostream& operator<<(ostream& os, const Dice& d) {
    os << "(" << d.v[0];
    for (int i = 1; i < 6; i++) {
        os << "," << d.v[i];
    }
    os << ")";
    return os;
}


