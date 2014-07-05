/* 重みつきUnionFind木 */
struct UnionFindW {
    int* parent;
    int* value;
    static const int INF = 1<<28;
    UnionFindW(int N) {
        parent = new int[N + 1]; fill(parent, parent + N + 1, -1);
        value = new int[N + 1]; fill(value, value + N + 1, 0);
    }
    ~UnionFindW() {
        delete[] parent;
        delete[] value;
    }
    /* 
     * root :: インデックス -> (ルートのインデックス, ルートとの距離)
     */
    pair<int, int> root(int x) {
        if (parent[x] == -1) return make_pair(x, 0);
        int p = parent[x];
        int v = value[x];
        pair<int, int> proot = root(p);
        parent[x] = proot.first;
        value[x] = v + proot.second;
        return make_pair(parent[x], value[x]);
    }
    /* 
     * query :: (インデックスx, インデックスy) -> yとxの差
     */
    int query(int x, int y) {
        pair<int, int> xroot = root(x),
                       yroot = root(y);
        if (xroot.first != yroot.first) return INF;
        return yroot.second - xroot.second;
    }
    /*
     * merge :: (インデックスx, インデックスy, yとxの差w) -> ()
     *
     * xとyがすでに親子関係を持っていて,その差がwでなければ異常終了
     */
    void merge(int x, int y, int w) {
        pair<int, int> xroot = root(x),
                       yroot = root(y);
        if (xroot.first == yroot.first) {
            assert(query(x, y) == w);
            return;
        }
        int px = xroot.first, py = yroot.first;
        int dx = xroot.second, dy = yroot.second;
        /* value[y] - value[x] = w
         * value[x] - value[px] = dx
         * value[y] - value[py] = dy
         * value[py] - value[px] = (value[y] - dy) - (value[x] - dx)
         *                       = (value[y] - value[x]) - (dy - dx)
         *                       = w - dy + dx
         */
        parent[py] = px;
        value[py] = w - dy + dx;
    }
};
