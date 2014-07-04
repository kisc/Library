#include "../../../Template.cpp"

#include "../../Geometry.cpp"

/**
 * となりあう3頂点が1直線上にあるクソ問題
 * 入力後, その頂点を消去することで対処
 */

#define next(i, n) ( (i + 1) % n )
#define prev(i, n) ( (i + n - 1) % n )
int main() {
    int n; cin >> n;
    vector<Point> vs(n);
    for (int i = 0; i < n; i++) {
        cin >> vs[i];
    }
    vector<bool> del(n, false);
    for (int i = 0; i < n; i++) {
        if (Point::CCW(vs[prev(i, n)], vs[i], vs[next(i, n)]) % 2 == 0) {
            // 3頂点が1直線上にある場合
            del[i] = true;
        }
    }
    vector<Point> vs2;
    for (int i = 0; i < n; i++) {
        if (!del[i]) {
            vs2.push_back(vs[i]);
        }
    }
    cout << Polygon(vs2).isConvex() << endl;
    return 0;
}
