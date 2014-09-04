#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
#define repeat(i,n) for (int i = 0; i < (n); ++i)

class MinCostFlow {
public:
    struct edge_t { int to, cap, cost, rev; };
    static int infinity;

    MinCostFlow() : graph() {}
    MinCostFlow(int n) : graph(n) {}

    vector<vector<edge_t> > graph; // adjacency_list

    int add_vertex() {
        graph.push_back(vector<edge_t>());
        return graph.size()-1;
    }

    void add_edge(int from, int to, int cap, int cost) {
        graph[from].push_back((edge_t){   to, cap, cost, (int)graph[  to].size() });
        graph[  to].push_back((edge_t){ from,  0, -cost, (int)graph[from].size() - 1 });
    }

    int run_destructive(int s, int t, int f) {
        int result = 0;
        vector<int> potential(graph.size(), 0);
        while (0 < f) {
            // update potential using dijkstra
            vector<int> distance(graph.size(), infinity); // minimum -
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
            if (distance[t] == infinity) return -1; // no such flow
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
int MinCostFlow::infinity = 1e9;
ostream & operator << (ostream & out, const MinCostFlow & mcf) {
    repeat (i,(int)mcf.graph.size()) repeat (j,(int)mcf.graph[i].size()) {
        if (i) out << endl;
        MinCostFlow::edge_t e = mcf.graph[i][j];
        out << i << " -> " << e.to << "\t: { cap : " << e.cap << ",\tcost : " << e.cost << ",\trev : " << e.rev;
    }
    return out;
}
