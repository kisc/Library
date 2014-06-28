#include "../../../Template.cpp"

#include "../../Geometry.cpp"

int main() {
    Point P0, P1, P2;
    cin >> P0;
    cin >> P1;
    int q;
    cin >> q;
    Point P = P1 - P0;
    for (int i = 0; i < q; i++) {
        cin >> P2;
        Point Q = P2 - P0;
        Point T = P0 + Point::Projection(P, Q);
        printf("%.12lf %.12lf\n", T.x, T.y);
    }
    return 0;
}

