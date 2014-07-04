#include "../../../Template.cpp"

#include "../../Geometry.cpp"

int main() {
    int q; cin >> q;
    while (q--) {
        Point a, b, c, d;
        cin >> a >> b >> c >> d;
        Segment s(a, b), t(c, d);
        cout << Segment::DoIntersect(s, t) << endl;
    }
    return 0;
}
