/* Dijkstra法により最短経路問題を解く.
 * 使用するときはWとINFを適当に定義. 
 *
 * 頂点のナンバリングは0-origin. */
struct Dijkstra {
    typedef Long W;
    enum { INF = (1LL << 56) };
    struct Edge {
        int from, to;
        W cost;
        Edge(int from, int to, W cost) :
            from(from), to(to), cost(cost) {}
    };
    vector< vector<Edge> > G;
    int V;
    /* コンストラクタの引数Vは頂点数 */
    Dijkstra(int V) : V(V) {
        G.resize(V, vector<Edge>());
    }
    /* 辺追加. from -> toの辺しか追加しないので注意. */
    void addEdge(int from, int to, W cost) {
        G[from].push_back(Edge(from, to, cost));
    }
    /* 引数に始点sをとり, 各頂点への最短経路を返す. */
    vector<W> solve(int s) {
        vector<W> D(V, INF);
        bool used[V]; memset(used, 0, sizeof(used));
        used[s] = true;
        D[s] = 0;
        priority_queue<S> PQ;
        PQ.push(S(s, 0));
        while (!PQ.empty()) {
            S cur = PQ.top(); PQ.pop();
            for (int i = 0; i < G[cur.v].size(); i++) {
                Edge& e = G[cur.v][i];
                if (D[e.to] > D[cur.v] + e.cost) {
                    D[e.to] = D[cur.v] + e.cost;
                    PQ.push(S(e.to, D[e.to]));
                }
            }
        }
        return D;
    }
    struct S {
        int v;
        W cost;
        S(int v, W cost) : v(v), cost(cost) {}
        bool operator<(const S& s) const {
            return cost > s.cost;
        }
    };
};
