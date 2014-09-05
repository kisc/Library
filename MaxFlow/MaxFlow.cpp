// Ford-Fulkerson algorithm
// O(Ef) -- f is the maxflow
class MaxFlow {
public:
    struct edge_t { int to; int cap; int rev; };

    MaxFlow() {}
    MaxFlow(int n) : graph(n) {}

    vector<vector<edge_t> > graph; // adjacency list

    void addEdge(int from, int to, int cap) {
        graph[from].push_back((edge_t){   to, cap, (int)graph[  to].size() });
        graph[  to].push_back((edge_t){ from,   0, (int)graph[from].size() - 1 });
    }

    vector<bool> used;

    int solve(int s, int t) {
        int flow = 0;
        used.resize(graph.size());
        while (true) {
            fill(used.begin(), used.end(), false);
            int f = dfs(s, t, 1e9);
            if (f == 0) return flow;
            flow += f;
        }
    }

    // search augmenting pathes from `v' to `t', returns the volume of water `f'
    int dfs(int v, int t, int f) {
        if (v == t) return f; // base case
        used[v] = true;
        repeat (i,(int)graph[v].size()) { // for each adjacent nodes which are not used and able to flow
            edge_t & e = graph[v][i];
            const int w = e.to;
            if (not used[w] and 0 < e.cap) {
                int d = dfs(w, t, min(f, e.cap)); // v -> w ->> t
                if (0 < d) { // let flow and make reverse capacity
                    e.cap -= d;
                    graph[w][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0; // path not found
    }
};
