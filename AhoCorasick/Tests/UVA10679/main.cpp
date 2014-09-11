#include "../../../Template.cpp"
#include "../../AhoCorasick.cpp"

string S;
vector<string> Q;

void input() {
    int Qs;
    cin >> S;
    cin >> Qs;
    Q.resize(Qs);
    for (int i = 0; i < Qs; i++) {
        cin >> Q[i];
    }
}

void solve() {
    AhoCorasick matcher(Q);
    vector<int> result;
    matcher.match(S, result);
    for (int i = 0; i < Q.size(); i++) {
        cout << (result[i] >= 1 ? "y" : "n") << endl;
    }
}

int main() {
    int T; scanf("%d\n", &T);
    for (int t = 1; t <= T; t++) {
        input(); solve();
    }
    return 0;
}
