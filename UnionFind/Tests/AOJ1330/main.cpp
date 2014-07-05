#include "../../../Template.cpp"
#include "../../UnionFindW.cpp"

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        UnionFindW uf(N);
        char c; int a, b, w;
        for (int i = 0; i < M; i++) {
            cin >> c;
            if (c == '?') {
                cin >> a >> b;
                int ans = uf.query(a, b);
                //cerr << "?" << " " << a << " " << b << endl;
                if (ans == UnionFindW::INF) {
                    cout << "UNKNOWN" << endl;
                } else {
                    cout << ans << endl;
                }
            } else {
                assert(c == '!');
                cin >> a >> b >> w;
                //cerr << "!" << " " << a << " " << b << " " << w << endl;
                uf.merge(a, b, w);
            }
        }
    }
    return 0;
}
