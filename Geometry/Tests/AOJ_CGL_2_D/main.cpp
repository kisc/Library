#include "../../../Template.cpp"

#include "../../Geometry.cpp"

int main() {
    int q; cin >> q;
    while (q--) {
        Segment s, t;
        cin >> s.a >> s.b >> t.a >> t.b;
        printf("%.12lf\n", Segment::Distance(s, t));
    }
    return 0;
}
