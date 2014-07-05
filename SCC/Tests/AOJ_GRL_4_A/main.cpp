#include "../../../Template.cpp"
#include "../../SCC.cpp"

int main() {
    int V, E; cin >> V >> E;
    SCC S(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        S.addEdge(s, t);
    }
    vector<int> scc = S.solve();
    sort(whole(scc));
    uniq(scc);
    cout << (V != scc.size()) << endl;
    return 0;
}
