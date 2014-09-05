#include "../../../Template.cpp"
#include "../../MaxFlow.cpp"
#define MAX_N 100
#define MAX_M 100

int main() {
    int T; cin >> T;
    int N; cin >> N;
    static int A[MAX_N]; repeat (n,N) cin >> A[n];
    int M; cin >> M;
    static int B[MAX_M]; repeat (m,M) cin >> B[m];
    MaxFlow mf(1+N+M+1);
    repeat (n,N) mf.addEdge(0,1+n,1);
    repeat (n,N) repeat (m,M) if (A[n] <= B[m] and B[m] <= A[n]+T) mf.addEdge(1+n,1+N+m,1);
    repeat (m,M) mf.addEdge(1+N+m,1+N+M,1);
    cout << (mf.solve(0,1+N+M) == M ? "yes" : "no") << endl;
    return 0;
}
