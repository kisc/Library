#include "../../../Template.cpp"
#include "../../GaussianElim.cpp"
int main() {
    // ax + by = c
    // dx + ey = f
    vector<vector<double> > v(2, vector<double>(3));
    vector<double> w;
    while (true) {
        repeat (i,2) repeat (j,3) cin >> v[i][j];
        if (cin.fail()) break;
        w = GaussianElim(v);
        printf("%.3lf %.3lf\n", w[0], w[1]);
    }
    return 0;
}
