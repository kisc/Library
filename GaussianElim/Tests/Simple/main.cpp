#include "../../../Template.cpp"
#include "../../GaussianElim.cpp"
int main() {
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<double> > a(n, vector<double>(m));
    repeat (i,n) repeat (j,m) cin >> a[i][j];
    vector<double> b = GaussianElim(a);
    repeat (i, (int)b.size()) { if (i) cout << ' '; cout << b[i]; }
    cout << endl;
    return 0;
}
