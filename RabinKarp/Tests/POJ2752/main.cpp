#include "../../../Template.cpp"
#include "../../RabinKarp.cpp"

int main() {
    while (true) {
        string s; cin >> s;
        if (not cin) break;
        vector<RabinKarp::hash_t> hash = RabinKarp::generateTable(s);
        vector<int> ans;
        repeat (i,(int)s.length()) {
            if (RabinKarp::subhash(hash,0,i+1) == RabinKarp::subhash(hash, s.length()-(i+1), s.length())) {
                ans.push_back(i+1);
            }
        }
        sort(ans.begin(), ans.end());
        repeat (i,(int)ans.size()) {
            if (0 < i) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
