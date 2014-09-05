#include <iostream>
#include <cmath>
using namespace std;
#define repeat(i,n) for (int i = 0; i < (n); ++i)
#include "../../MinCostFlow.cpp"

#define MAX_N (100)
int N;
static int P[MAX_N];
int A(int i) { return i; }
int B(int i) { return N+i; }
int S() { return N*2; }
int T() { return N*2+1; }
int graph_size() { return N*2+2; }
int cost(int i, int j) {
    return ((i == N*2 and j < N) ? 0 :
            (i < N and N <= j and j < N*2) ? (P[i] + P[j-N]) * (j-N - i) :
            (N <= i and i < N*2 and j == N*2+1) ? 0 :
            cost(i,j) /* diverge */);
}

int main() {
    cin >> N;
    repeat (i,N) cin >> P[i];

    // min cost flow of such a graph:
    /*         S      -- S N*2
     *     / / | \ \
     *     5 3 1 2 4  -- A i
     *     . . . . |
     *             |
     *     +-+-+---+
     *     | | |   |
     *     1 2 3 4 5  -- B N+i
     *     \ \ | / /
     *         T      -- T N*2+1
     */
    // the swap means:
    /*    1   2
     *     \ /    1 -> 2 : cost 1
     *      X     2 -> 1 : cost 2
     *     / \  the swap : cost 3
     *    1   2
     */
    static MinCostFlow mcf(graph_size());
    repeat (i,N) repeat (j,N) if (P[i]-1 != j) {
        mcf.addEdge(A(i), B(j), 1, P[i] * abs(i - j));
    }
    repeat (i,N) {
        mcf.addEdge(S(), A(i), 1, 0);
        mcf.addEdge(T(), 1, 0);
    }
    cout << mcf.solve(S(), T(), N) << endl;
}
