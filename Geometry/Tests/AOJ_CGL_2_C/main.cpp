#include "../../../Template.cpp"

namespace Geometry {
#include "../../Geometry.cpp"
}

typedef Geometry::Point Point;
typedef Geometry::Line Line;
int main() {
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        Line l, m;
        cin >> l.a >> l.b >> m.a >> m.b;
        Point p = Line::Intersection(l, m);
        printf("%.12lf %.12lf\n", p.x, p.y);
    }
    return 0;
}
