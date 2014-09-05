class MinCostFlow {
public:
    struct edge_t { int to, cap, cost, rev; };

    MinCostFlow() : graph() {}
    MinCostFlow(int n) : graph(n) {}

    vector<vector<edge_t> > graph; // adjacency_list

    void addEdge(int from, int to, int cap, int cost) {
        graph[from].push_back((edge_t){   to, cap, cost, (int)graph[  to].size() });
        graph[  to].push_back((edge_t){ from,  0, -cost, (int)graph[from].size() - 1 });
    }

    int solve(int s, int t, int f) {
        int result = 0;
        vector<int> potential(graph.size(), 0);
        while (0 < f) {
            // update potential using dijkstra
            vector<int> distance(graph.size(), 1e9); // minimum -
            vector<int> prev_v(graph.size()); // constitute a single-linked-list represents the flow-path
            vector<int> prev_e(graph.size());
            { // initialize distance and prev_{v,e}
                priority_queue<pii, vector<pii>, greater<pii> > q; // distance * vertex
                distance[s] = 0;
                q.push(pii(0,s));
                while (not q.empty()) {
                    int d = q.top().first;
                    int v = q.top().second; q.pop();
                    if (distance[v] < d) continue;
                    // look round the vertex
                    repeat (e_ix,(int)graph[v].size()) {
                        // consider updating
                        edge_t & e = graph[v][e_ix];
                        int w = e.to;
                        int d1 = distance[v] + e.cost + potential[v] - potential[w]; // updated distance
                        if (0 < e.cap and d1 < distance[e.to]) {
                            distance[w] = d1;
                            prev_v[w] = v;
                            prev_e[w] = e_ix;
                            q.push(pii(d1,w));
                        }
                    }
                }
            }
            if (distance[t] == 1e9) return -1; // no such flow
            repeat (v,(int)graph.size()) potential[v] += distance[v];
            {
                int d = f;
                // let flow on the s->t minimum path
                for (int v = t; v != s; v = prev_v[v]) {
                    d = min(d, graph[prev_v[v]][prev_e[v]].cap);
                }
                f -= d;
                result += d * potential[t];
                for (int v = t; v != s; v = prev_v[v]) {
                    edge_t & e = graph[prev_v[v]][prev_e[v]];
                    e.cap -= d;
                    graph[v][e.rev].cap += d;
                }
            }
        }
        return result;
    }
};
ostream & operator << (ostream & out, const MinCostFlow & mcf) {
    repeat (i,(int)mcf.graph.size()) repeat (j,(int)mcf.graph[i].size()) {
        if (i) out << endl;
        MinCostFlow::edge_t e = mcf.graph[i][j];
        out << i << " -> " << e.to << "\t: { cap : " << e.cap << ",\tcost : " << e.cost << ",\trev : " << e.rev;
    }
    return out;
}
