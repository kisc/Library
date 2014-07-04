#include "../../../Template.cpp"
#include "../../Geometry.cpp"

int main() {
    int n;
    cin >> n;
    vector<Point> vs(n);
    for (int i = 0; i < n; i++) {
        cin >> vs[i];
    }
    vector<Point> P = Polygon::ConvexHull(vs).vs;
    int MinIndex = 0;
    for (int i = 1; i < P.size(); i++) {
        if (Point::CompY(P[i], P[MinIndex])) {
            MinIndex = i;
        }
    }
    cout << P.size() << endl;
    cout << P[MinIndex].x << " " << P[MinIndex].y << endl;
    for (int i = (MinIndex + 1) % P.size() ; i != MinIndex; i = (i + 1) % P.size()) {
        cout << P[i].x << " " << P[i].y << endl;
    }
    return 0;
}
