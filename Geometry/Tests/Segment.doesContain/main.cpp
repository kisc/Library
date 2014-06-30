#include "../../../Template.cpp"
#include "../../Geometry.cpp"

int main() {
    int q;
    cin >> q;
    while (q--) {
        Segment s;
        cin >> s.a >> s.b;
        Point p;
        cin >> p;
        cout << s.doesContain(p) << endl;
    }
    return 0;
}
