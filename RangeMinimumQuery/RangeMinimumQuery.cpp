struct RangeMinimumQuery {
    int N;
    int* v;
    static const int INF = (1LL << 31) - 1;
    static int FindPow2(int x) {
        int x1 = 1;
        while (x1 < x) {
            x1 *= 2;
        }
        return x1;
    }
    RangeMinimumQuery(int N_, int init = 0) : N(FindPow2(N_)) {
        v = new int[N * 2];
        fill(v, v + N * 2, init);
    }
    ~RangeMinimumQuery() {
        delete[] v;
    }
    int dfs(int s, int t, int a, int b, int k) {
        if (s <= a && b <= t) return v[k];
        if (t <= a || b <= s) return INF;
        int m = (a + b) / 2;
        return min(dfs(s, t, a, m, k * 2), dfs(s, t, m, b, k * 2 + 1));
    }
    // 半開区間[s, t)の要素のうち最小のものを返す
    int query(int s, int t) {
        return dfs(s, t, 0, N, 1);
    }
    // 要素iをxに
    void update(int i, int x) {
        i += N;
        v[i] = x;
        while (i > 0) {
            i /= 2;
            v[i] = min(v[i * 2], v[i * 2 + 1]);
        }
    }
};
