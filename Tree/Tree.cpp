/* 木 
 * グラフがちゃんと木になっているかどうか確認しないので注意. */
struct Tree {
    typedef Long W;
    struct Edge {
        int from, to;
        W cost;
        Edge(int from, int to, W cost) :
            from(from), to(to), cost(cost) {}
    };
    vector< vector<Edge> > G;
    int V;
    Tree(int V) : V(V) {
        G.resize(V, vector<Edge>());
    }
    void addEdge(int from, int to, W cost) {
        G[from].push_back(Edge(from, to, cost));
        G[to].push_back(Edge(to, from, cost));
    }
    /* 直径の両端 */
    pair<int, int> diameter() {
        vector<W> d;
        int s = 0;
        CalcDistance(s, d);
        s = max_element(whole(d)) - d.begin();
        CalcDistance(s, d);
        return make_pair(s, max_element(whole(d)) - d.begin());
    }
    /* 2点間の距離 */
    W distance(int from, int to) {
        vector<W> d;
        CalcDistance(from, d);
        return d[to];
    }
    /* 始点fromから各頂点への距離をdに格納 */
    void CalcDistance(int from, vector<W>& d) {
        bool used[V]; 
        d.resize(V);
        memset(used, 0, sizeof(used));
        used[from] = true;
        queue<int> Q;
        Q.push(from);
        d[from] = 0;
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for (int i = 0; i < G[cur].size(); i++) {
                Edge& e = G[cur][i];
                if (used[e.to]) continue;
                d[e.to] = d[e.from] + e.cost;
                used[e.to] = true;
                Q.push(e.to);
            }
        }
    }
};
