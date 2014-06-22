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

#include "../../RangeMinimumQuery.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    RangeMinimumQuery rmq(n, RangeMinimumQuery::INF);
    for (int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            rmq.update(x, y);
        } else {
            cout << rmq.query(x, y + 1) << endl;
        }
    }
    return 0;
}
