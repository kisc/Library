#include "../../../Template.cpp"

#include "../../Geometry.cpp"

/**
 * 頂点が右まわりで与えられるのか左まわりで与えられるのか不定
 * 最初の3頂点が右まわりなら頂点の順番を反転することで対処
 */

int main() {
    int N;
    while (cin >> N, N != 0) {
        vector<Point> vs(N);
        for (int i = 0; i < N; i++) cin >> vs[i];
        if (Point::CCW(vs[0], vs[1], vs[2]) == -1) {
            // 3頂点が右まわり
            reverse(whole(vs));
        }
        cout << (Polygon(vs).isConvex() ? "No" : "Yes") << endl;
    }
    return 0;
}
