#include "../../../Template.cpp"
#include "../../Dice.cpp"

vector<Dice> Ds;
const Dice XDice(1, 2, 3);
int N;
bool input() {
    cin >> N;
    if (N == 0) return false;
    Ds.clear();
    //cerr << XDice << endl;
    for (int t = 0; t < N; t++) {
        int top, front; cin >> top >> front;
        for (int r = 1; r <= 6; r++) {
            if (top == r || front == r) continue;
            if (top == 7 - r || front == 7 - r) continue;
            Dice a(top, front, r);
            if (a.isSameDice(XDice)) {
                Ds.push_back(a);
                break;
            }
        }
    }
    return true;
}

#define MN 100
int Level[MN * 2 + 1][MN * 2 + 1];
int Top[MN * 2 + 1][MN * 2 + 1];

#define x(n) ((n) + 100)

int FindFace(const Dice& d, int face) {
    for (int dir = 0; dir < 6; dir++) {
        if (d.v[dir] == face) return dir;
    }
    assert(0);
}

void Roll(Dice& d, Dice::FACE dir) {
    //cerr << d << " " << dir << endl;
    switch (dir) {
        case Dice::FRONT: for (int i = 0; i < 3; i++) d.rollX(); break;
        case Dice::BACK: d.rollX(); break;
        case Dice::RIGHT: d.rollY(); break;
        case Dice::LEFT: for (int i = 0; i < 3; i++) d.rollY(); break;
        default: assert(0);
    }
}

// FRONT, BACK, LEFT, RIGHT
const int dx[] = {0, 0, 1, -1},
          dy[] = {1, -1, 0, 0};

void Fall(Dice d) {
    int X = x(0), Y = x(0);
    Level[X][Y]++;
    while (true) {
        bool flag = false;
        for (int i = 6; i >= 4; i--) {
            int dir = FindFace(d, i);
            if (dir == Dice::TOP || dir == Dice::BOTTOM) continue;
            int nX = X, nY = Y;
            switch (dir) {
                case Dice::FRONT: nY++; break;
                case Dice::BACK:  nY--; break;
                case Dice::RIGHT: nX++; break;
                case Dice::LEFT:  nX--; break;
                default: assert(0);
            }
            if (Level[X][Y] <= Level[nX][nY] + 1) continue;
            //cerr << X - x(0) << " " << Y - x(0) << " " << Level[X][Y] << " " << Level[nX][nY] << endl;
            Level[X][Y]--;
            Level[nX][nY]++;
            Roll(d, Dice::FACE(dir));
            flag = true;
            X = nX;
            Y = nY;
            break;
        }
        if (!flag) break;
    }
    Top[X][Y] = d.v[Dice::TOP];
}

void solve() {
    memset(Level, 0, sizeof(Level));
    memset(Top, 0, sizeof(Top));
    for (int i = 0; i < N; i++) {
        Fall(Ds[i]);
    }
    int Ans[7]; memset(Ans, 0, sizeof(Ans));
    for (int i = 0; i <= 2 * MN; i++) {
        for (int j = 0; j <= 2 * MN; j++) {
            Ans[ Top[i][j] ]++;
        }
    }
    cout << Ans[1];
    for (int i = 2; i <= 6; i++) {
        cout << " " << Ans[i];
    }
    cout << endl;
}

int main() {
    while (input()) {
        solve();
    }
    return 0;
}
