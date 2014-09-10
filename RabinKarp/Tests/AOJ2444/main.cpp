#include "../../../Template.cpp"
#include "../../RabinKarp.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    string s; cin >> s;
    set<RabinKarp::hash_t> ans;
    vector<RabinKarp::hash_t> hash = RabinKarp::generateTable(s);
    int l = 0, r = 1; // [l,r)
    repeat (k,m) {
        string query; cin >> query;
        if      (query == "L++") ++ l;
        else if (query == "L--") -- l;
        else if (query == "R++") ++ r;
        else if (query == "R--") -- r;
        else assert(false);
        ans.insert(RabinKarp::subhash(hash, l, r));
    }
    cout << ans.size() << endl;
    return 0;
}
