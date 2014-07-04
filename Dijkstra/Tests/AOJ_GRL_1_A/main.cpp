#include "../../../Template.cpp"
#include "../../Dijkstra.cpp"

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    Dijkstra D(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        D.addEdge(s, t, d);
    }
    vector<Long> Ans = D.solve(r);
    for (int i = 0; i < V; i++) {
        if (Ans[i] == Dijkstra::INF) {
            cout << "INF" << endl;
        } else {
            cout << Ans[i] << endl;
        }
    }
    return 0;
}
