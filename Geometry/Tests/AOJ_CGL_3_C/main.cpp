#include "../../../Template.cpp"

#include "../../Geometry.cpp"

int main() {
    int n, q;
    cin >> n;
    vector<Point> vs(n);
    for (int i = 0; i < n; i++) cin >> vs[i];
    Polygon P(vs);
    cin >> q;
    for (int i = 0; i < q; i++) {
        Point p; cin >> p;
        //cout << p << ": ";
        if (P.edgesContain(p)) {
            cout << 1 << endl;
        } else if (P.contains(p)) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
