/* Strongly Connected Components */
struct SCC {
    vector< vector<int> > G1, G2;
    int V;
    SCC(int V) : V(V) {
        G1.resize(V, vector<int>());
        G2.resize(V, vector<int>());
    }
    void addEdge(int from, int to) {
        G1[from].push_back(to);
        G2[to].push_back(from);
    }
    bool* used;
    vector<int> vs;
    void dfs1(int v) {
        used[v] = true;
        for (int i = 0; i < G1[v].size(); i++) {
            if (!used[ G1[v][i] ]) dfs1(G1[v][i]);
        }
        vs.push_back(v);
    }
    void dfs2(int v, int k, vector<int>& order) {
        used[v] = true;
        order[v] = k;
        for (int i = 0; i < G2[v].size(); i++) {
            if (!used[ G2[v][i] ]) dfs2(G2[v][i], k, order);
        }
    }
    /* 強連結成分分解後の各頂点のトポロジカル順序を返す */
    vector<int> solve() {
        used = new bool[V];
        fill(used, used + V, false);
        vs.clear();
        for (int v = 0; v < V; v++) {
            if (!used[v]) dfs1(v);
        }
        fill(used, used + V, false);
        int k = 0;
        vector<int> Ret(V, -1);
        for (int i = vs.size() - 1; i >= 0; i--) {
            if (!used[vs[i]]) dfs2(vs[i], k++, Ret);
        }
        delete[] used;
        return Ret;
    }
};
