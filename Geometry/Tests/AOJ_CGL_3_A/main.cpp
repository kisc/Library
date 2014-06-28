#include "../../../Template.cpp"

#include "../../Geometry.cpp"

int main() {
    int n; cin >> n;
    vector<Point> vs(n);
    for (int i = 0; i < n; i++) cin >> vs[i];
    printf("%.1lf\n", Polygon(vs).area());
    return 0;
}
