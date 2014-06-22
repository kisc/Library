struct UnionFind {
    int* parent;
    int N;
    UnionFind(int N) : N(N) {
        parent = new int[N];
        fill(parent, parent + N, -1);
    }
    ~UnionFind() {
        delete[] parent;
    }
    int root(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = root(parent[x]);
    }
    bool query(int x, int y) {
        return root(x) == root(y);
    }
    void merge(int x, int y) {
        x = root(x); 
        y = root(y);
        if (x != y) {
            parent[x] = y;
        }
    }
};

