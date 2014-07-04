#include "../../../Template.cpp"
#include "../../Geometry.cpp"

Segment s[3];
bool input() {
    cin >> s[0].a >> s[0].b;
    if (s[0].a == Point(0, 0) && s[0].b == Point(0, 0)) return false;
    for (int i = 1; i < 3; i++) {
        cin >> s[i].a >> s[i].b;
    }
    return true;
}

void solve() {
    vector<Point> P;
    for (int i = 0; i < 3; i++) {
        if (Segment::DoIntersect(s[i], s[(i + 1) % 3])) {
            P.push_back(Line::Intersection(s[i], s[(i + 1) % 3]));
        }
    }
    if (P.size() == 3) {
        double Area = abs(Polygon(P).area());
        if (Area >= 19e5) {
            cout << "dai-kichi" << endl;
        } else if (Area >= 1e6) {
            cout << "chu-kichi" << endl;
        } else if (Area >= 1e5) {
            cout << "kichi" << endl;
        } else if (Area > 0) {
            cout << "syo-kichi" << endl;
        } else {
            cout << "kyo" << endl;
        }
    } else {
        cout << "kyo" << endl;
    }
}

int main() {
    while (input()) solve();
    return 0;
}
