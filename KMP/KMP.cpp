/* KMP法による文字列探索
 * 計算量 O(M + N). M: パターンの長さ, N: パターンを探す文字列の長さ */
struct KMP {
    string s;
    vector<int> PMA;
    KMP(const string &s) : s(s) {
        buildPMA(s);
    }
    /* tに含まれるsの数を数える.
     * この実装では
     *   s = "ABA",
     *   t = "ABABA"
     * のとき2 ( [0, 3), [2, 5)でマッチ ) を返す.
     * [2, 5)でマッチさせたくなければbuildPMAでPMA[M]を0にしておく. */
    int match(const string& t) {
        int N = t.size(), M = s.size();
        int Count = 0;
        int si = 0, ti = 0;
        while (ti < N) {
            if (s[si] == t[ti]) {
                si++; ti++;
            } else {
                if (si == 0) ti++;
                si = PMA[si];
            }
            if (si == M) {
                Count++; // [ti - M, ti)でマッチ
                si = PMA[si];
            }
        }
        return Count;
    }
    /* Pattern Matching Automaton を作る */
    void buildPMA(const string& s) {
        int M = s.size();
        PMA.resize(M + 1);
        PMA[0] = 0; PMA[1] = 0;
        for (int i = 2; i <= M; i++) {
            int j = PMA[i - 1];
            while (true) {
                if (s[j] == s[i - 1]) { PMA[i] = j + 1; break; }
                if (j == 0) { PMA[i] = 0; break; }
                j = PMA[j];
            }
        }
    }
};
