#include "../../../Template.cpp"
#include "../../../UnionFind/UnionFind.cpp"
#include "../../Kruskal.cpp"

Long Sum(const vector<Long>& xs) {
    Long Ret = 0;
    for (int i = 0; i < xs.size(); i++) 
        Ret += xs[i];
    return Ret;
}

int main() {
    int V, E;
    cin >> V >> E;
    Kruskal K(V);
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        K.addEdge(s, t, w);
    }
    cout << Sum(K.solve()) << endl;
    return 0;
}

