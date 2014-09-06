/* 区間への一様加算に対応したRangeSumQuery */
struct RangeSumQuery2 {
    // rootのindexは1
    int N;
    vector<Long> V, L;
    static int FindPow2(int x) {
        int x1 = 1;
        while (x1 < x) x1 *= 2;
        return x1;
    }
    RangeSumQuery2(int N_) : N(FindPow2(N_)) {
        V = vector<Long>(N * 2, 0);
        L = vector<Long>(N * 2, 0);
    }
    /* [s, t)に一様にxを加算 */
    void add(Long x, int s, int t) { return add(x, s, t, 0, N, 1); }
    void add(Long x, int s, int t, int a, int b, int k) {
        if (t <= a || b <= s) return;
        if (s <= a && b <= t) {
            L[k] += x;
            return;
        }
        if (s < b || a < t) {
            V[k] += (min(t, b) - max(s, a)) * x;
            if (b - a == 1) return;
            int m = (a + b) / 2;
            add(x, s, t, a, m, k * 2);
            add(x, s, t, m, b, k * 2 + 1);
        }
    }
    /* [s, t)の和 */
    Long query(int s, int t) { return query(s, t, 0, N, 1); }
    Long query(int s, int t, int a, int b, int k) {
        if (t <= a || b <= s) return 0;
        if (s <= a && b <= t) return V[k] + L[k] * (b - a);
        int m = (a + b) / 2;
        return (min(t, b) - max(s, a)) * L[k] +
            query(s, t, a, m, k * 2) +
            query(s, t, m, b, k * 2 + 1);
    }
};
