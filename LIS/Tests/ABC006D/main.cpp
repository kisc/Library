#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
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
#include <set>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

typedef long long Long;
#define whole(xs) xs.begin(), xs.end()

#include "../../LIS.cpp"

int main() {
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    cout << N - LIS(v) << endl;
    return 0;
}
