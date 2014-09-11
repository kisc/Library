#include "../../../Template.cpp"
#include "../../AhoCorasick.cpp"

int N;
vector<string> P;
string S;

bool input() {
    cin >> N;
    if (N == 0) return false;
    P.resize(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    cin >> S;
    return true;
}

void solve() {
    AhoCorasick matcher(P);
    vector<int> result;
    matcher.match(S, result);
    int M = *max_element(whole(result));
    cout << M << endl;
    for (int i = 0; i < N; i++) {
        if (M == result[i]) {
            cout << P[i] << endl;
        }
    }
}

int main() {
    while (input()) solve();
    return 0;
}
