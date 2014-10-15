std::pair<std::vector<double>,int> GaussianElimWithRank(std::vector<std::vector<double> > a) {
    const double eps = 1e-5;
    const int n = a.size();
    if (n == 0) return std::make_pair(std::vector<double>(0), 0);
    const int m = a[0].size();
#ifdef DEBUG
    repeat (i, n) assert ((int)a[i].size() == m);
#endif
    std::vector<std::vector<double> > indep;
    {
        int i = 0, j = 0;
        while (i < n and j < m-1) {
            int pivot = -1;
            repeat_from (k, i, n) {
                if (eps < std::abs(a[k][j])) {
                    // pivot = k; break;
                    pivot = pivot == - 1 ? k : (std::abs(a[pivot][j]) < std::abs(a[k][j]) ? k : pivot);
                }
            }
            if (pivot == -1) {
                repeat (k,m) {
                    if (eps < std::abs(a[i][k])) {
                        if  (k == m-1) {
                            return std::make_pair(std::vector<double>(0), -1);
                        } else {
                            j += 1;
                            i -= 1; // dont incr i
                            break;
                        }
                    }
                }
                i += 1;
                continue;
            } else {
                if (pivot != i) std::swap(a[i], a[pivot]);
                repeat_from (k, i+1, m) a[i][k] /= a[i][i];
                a[i][i] = 1;
                repeat_from (k, i+1, n) {
                    repeat_from (l, i+1, m) {
                        a[k][l] -= a[k][i] * a[i][l];
                    }
                    a[k][i] = 0;
                }
                indep.push_back(a[i]);
                i += 1; j += 1;
            }
        }
        while (i < n) {
            if (eps < std::abs(a[i][m-1])) {
                return std::make_pair(std::vector<double>(0), -1);
            }
            i += 1;
        }
    }
    if ((int)indep.size() < m-1) return std::make_pair(std::vector<double>(0), indep.size());
#ifdef DEBUG
    assert ((int)indep.size() == m-1);
#endif
    // gather the solutions
    std::vector<double> result(m-1);
    repeat_rev (i, m-1) {
        result[i] = indep[i][m-1];
        repeat_from (j, i+1, m-1) {
            result[i] -= indep[i][j] * result[j];
        }
    }
    return std::make_pair(result, m-1);
}

// a11x1 + a12x2 + ... + a1m-1xm-1 = a1m
// a21x1 + a22x2 + ... + a2m-1xm-1 = a2m
//      ...        ...            ...
// an1x1 + an2x2 + ... + anm-1xm-1 = anm
std::vector<double> GaussianElim(std::vector<std::vector<double> > a) {
    return GaussianElimWithRank(a).first;
}
