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
#include <stack>
#include <utility>
#include <vector>

using namespace std;

const double EPS = 1e-9;
const double INF = 1e10;

typedef long long Long;
typedef unsigned long long ULong;
typedef pair<int,int> pii;
#define whole(xs) xs.begin(), xs.end()
#define EQ(a, b) (abs((a) - (b)) < EPS)
#define uniq(xs) (xs.erase(unique(xs.begin(), xs.end()), xs.end()))
#define repeat(i,n) for (int i = 0; i < (n); ++i)
