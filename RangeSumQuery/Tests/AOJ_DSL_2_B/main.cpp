#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

typedef long long Long;
#define whole(xs) xs.begin(), xs.end()

#include "../../RangeSumQuery.cpp"

int main() {
    int n, q; cin >> n >> q;
    RangeSumQuery rsq(n + 1, 0);
    for (int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            rsq.add(x, y);
        } else {
            cout << rsq.query(x, y + 1) << endl;
        }
    }
    return 0;
}
