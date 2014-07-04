#include "../../../Template.cpp"

#include "../../Geometry.cpp"

// (2直線が平行) <=> (直線を表すベクトルの外積が0)
// (2直線が直行) <=> (直線を表すベクトルの内積が0)
int main() {
    int q; cin >> q;
    while (q--) {
        Point a, b, c, d; 
        cin >> a >> b >> c >> d;
        Point l = b - a, m = d - c;
        if (Point::Cross(l, m) == 0) {
            cout << 2 << endl;
        } else if (Point::Dot(l, m) == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
