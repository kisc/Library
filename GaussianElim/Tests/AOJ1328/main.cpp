#include "../../../Template.cpp"
#include "../../GaussianElim.cpp"
int solve(int d, vector<double> & f, vector<vector<double> > & a) {
    vector<double> b(a[0].size(), 0);
    repeat (wrong,d+3) {
        a[wrong].swap(b);
        if (GaussianElimWithRank(a).second != -1) {
            return wrong;
        }
    }
    assert(false);
}
int main() {
    ios_base::sync_with_stdio(false);
    while (true) {
        int d; cin >> d;
        if (d == 0) break;
        vector<double> f(d+3); repeat (i,d+3) cin >> f[i];
        vector<vector<double> > a(d+3, vector<double>(d+2));
        repeat (i,d+3) repeat (j,d+2) {
            a[i][j] = (0 <= d-j) ? pow(i, d-j) : f[i];
        }
        cout << solve(d,f,a) << endl;
    }
    return 0;
}
