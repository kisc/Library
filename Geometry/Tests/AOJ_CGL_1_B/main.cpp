#include "../../../Template.cpp"

#include "../../Geometry.cpp"

int main() {
    Point P0, P1, P2;
    cin >> P0 >> P1;
    Line L(P0, P1);
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> P2;
        Point T = L.Reflection(P2);
        printf("%.12lf %.12lf\n", T.x, T.y);
    }
    return 0;
}
