#include "../../../Template.cpp"
#include "../../SCC.cpp"

int main() {
    int V, E;
    cin >> V >> E;
    SCC S(V);
    for (int i = 0; i < E; i++) {
        int s, t; cin >> s >> t;
        S.addEdge(s, t);
    }
    vector<int> scc = S.solve();
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v; cin >> u >> v;
        cout <<  (scc[u] == scc[v]) << endl;
    }
    return 0;
}
