#include "../../../Template.cpp"
#include "../../Tree.cpp"

int main() {
    int n; cin >> n;
    Tree T(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        T.addEdge(s, t, w);
    }
    pair<int, int> Diameter = T.diameter();
    cout << T.distance(Diameter.first, Diameter.second) << endl;
    return 0;
}
