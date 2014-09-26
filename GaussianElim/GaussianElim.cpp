// a11x1 + a12x2 + ... + a1m-1xm-1 = a1m
// a21x1 + a22x2 + ... + a2m-1xm-1 = a2m
//      ...        ...            ...
// an1x1 + an2x2 + ... + anm-1xm-1 = anm
vector<double> GaussianElim(vector<vector<double> > a) {
    const int n = a.size();
#ifdef DEBUG
    assert (0 < n);
#endif
    const int m = a[0].size();
#ifdef DEBUG
    repeat (i, n) assert ((int)a[i].size() == m);
    assert (n == m-1);
#endif
    // make an upper diagonal matrix
    repeat (i, n) {
        {
            int pivot = -1;
            repeat_from (j, i, n) {
                const double eps = 1e-16;
                if (eps < abs(a[j][i])) { pivot = j; break; }
            }
#ifdef DEBUG
            assert (pivot != -1);
#endif
            if (pivot != i) swap(a[i], a[pivot]);
        }
        repeat_from (j, i+1, m) a[i][j] /= a[i][i];
        a[i][i] = 1;
        repeat_from (j, i+1, n) {
            repeat_from (k, i+1, m) {
                a[j][k] -= a[j][i] * a[i][k];
            }
            a[j][i] = 0;
        }
    }
    // gather the solutions
    vector<double> result(n);
    repeat_rev (i, n) {
        result[i] = a[i][m-1];
        repeat_from (j, i+1, n) {
            result[i] -= a[i][j] * result[j];
        }
    }
    return result;
}
