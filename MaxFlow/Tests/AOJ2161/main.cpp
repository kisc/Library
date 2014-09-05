#include "../../../Template.cpp"
#include "../../MaxFlow.cpp"

int sq(int x) { return x*x; }
double hypot(int x, int y) { return sqrt(sq(x)+sq(y)); }
double distance(int ax, int ay, int bx, int by) { return hypot(ax-bx,ay-by); }
template <class T, class S>
double distance(const T & a, const S & b) { return hypot(a.x-b.x,a.y-b.y); }

#define MAX_N 100
#define MAX_M 100
struct troop_t { int x, y, v; };
struct base_t  { int x, y; };
double time(const troop_t & t, const base_t & b) { return distance(t,b) /(double) t.v; }
struct path_t { int n, m; double t; };
bool operator < (const path_t & a, const path_t & b) { return make_pair(a.t,make_pair(a.n,a.m)) < make_pair(b.t,make_pair(b.n,b.m)); }

int main() {
    while (true) {
        int N, M; cin >> N >> M;
        if (N == 0 or M == 0) break;
        static troop_t T[MAX_N]; repeat (n,N) cin >> T[n].x >> T[n].y >> T[n].v;
        static base_t  B[MAX_M]; repeat (m,M) cin >> B[m].x >> B[m].y;

        static path_t p[MAX_N*MAX_M];
        repeat (n,N) repeat (m,M) p[M*n+m] = (path_t){ n, m, time(T[n],B[m]) };
        sort(p, p+N*M);

        int low = M, high = N*M; // the answer is in [low,high]
        while (low < high) {
            int mid = (low + high) / 2;
            MaxFlow mf(1+N+M+1);
            repeat (n,N)   mf.addEdge(0,        1+n,        1);
            repeat (i,mid) mf.addEdge(1+p[i].n, 1+N+p[i].m, 1);
            repeat (m,M)   mf.addEdge(1+N+m,    1+N+M,      1);
            int f = mf.solve(0, 1+N+M);
            if (f < M) {
                low = mid+1; // the answer is in (mid,high]
            } else {
                high = mid;
            }
        }
        printf("%.8lf\n", p[low-1].t);
    }
    return 0;
}
