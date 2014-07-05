/* BellmanFord法により最短経路問題を解く.
 * 負閉路の検出も同時に行う. */
struct BellmanFord {
    typedef Long W;
    enum { INF = (1LL << 56) };
    struct Edge {
        int from, to;
        W cost;
        Edge(int from, int to, W cost) :
            from(from), to(to), cost(cost) {}
    };
    vector<Edge> G;
    int V;
    BellmanFord(int V) : V(V) {}
    void addEdge(int from, int to, W cost) {
        G.push_back(Edge(from, to, cost));
    }
    typedef pair< bool, vector<W> > RetVal;
    /* RetVal :: (負閉路が存在するか, 始点から各頂点への最短距離) */
    RetVal solve(int s) {
        vector<W> D(V, INF);
        int UpdateCount = 1;
        int E = G.size();
        D[s] = 0;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < E; i++) {
                Edge& e = G[i];
                if (D[e.from] == INF) continue;
                if (D[e.to] > D[e.from] + e.cost) {
                    D[e.to] = D[e.from] + e.cost;
                    flag = true;
                    UpdateCount++;
                }
            }
            if (UpdateCount > V * V) {
                return RetVal(false, vector<W>());
            }
        }
        return RetVal(true, D);
    }
};
