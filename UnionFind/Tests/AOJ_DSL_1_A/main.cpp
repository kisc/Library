/* 
 * AOJ DSL_1 - A
 */
#include <iostream>
#include <algorithm>

using namespace std;
#include "../../UnionFind.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n + 1);
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) {
            uf.merge(x, y);
        } else {
            cout << uf.query(x, y) << endl;
        }
    }
}
