#include "../../../Template.cpp"
#include "../../BellmanFord.cpp"

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    BellmanFord B(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        B.addEdge(s, t, d);
    }
    BellmanFord::RetVal Ans = B.solve(r);
    if (Ans.first) {
        for (int i = 0; i < V; i++) {
            if (Ans.second[i] == BellmanFord::INF) {
                cout << "INF" << endl;
            } else {
                cout << Ans.second[i] << endl;
            }
        }
    } else {
        cout << "NEGATIVE CYCLE" << endl;
    }
    return 0;
}
