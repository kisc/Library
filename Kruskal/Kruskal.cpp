/* Kruskal法により最小全域木を求める */

// ここにUnionFindを展開
struct Kruskal {
    typedef Long W;
    struct Edge {
        int from, to;
        W cost;
        Edge(int from, int to, W cost) :
            from(from), to(to), cost(cost) {}
        bool operator<(const Edge& e) const {
            return cost < e.cost;
        }
    };
    vector<Edge> G;
    int V;
    Kruskal(int V) : V(V) {}
    void addEdge(int from, int to, W cost) {
        G.push_back(Edge(from, to, cost));
    }
    vector<W> solve() {
        sort(whole(G));
        vector<W> Ret;
        UnionFind uf(V);
        for (int i = 0; i < G.size(); i++) {
            if (uf.query(G[i].from, G[i].to)) continue;
            uf.merge(G[i].from, G[i].to);
            Ret.push_back(G[i].cost);
        }
        return Ret;
    }
};
