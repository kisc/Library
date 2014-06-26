// Longest Increasing Subsequence
int LIS(vector<int>& xs) {
    vector<int> L(xs.size(), INT_MAX);
    for (int i = 0; i < xs.size(); i++) {
        (*lower_bound(whole(L), xs[i])) = xs[i];
    }
    return lower_bound(whole(L), INT_MAX) - L.begin();
}
