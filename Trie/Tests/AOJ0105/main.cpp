#include "../../../Template.cpp"
#include "../../Trie.cpp"

int main() {
    string s; int p;
    TrieMap map;
    vector<string>rmap;
    vector< vector<int> > pages;
    int id = 0;
    while (cin >> s >> p) {
        if (!map.find(s)) {
            pages.push_back(vector<int>());
            rmap.push_back(s);
            map.set(s, id++);
        }
        pages[map.get(s)].push_back(p);
    }
    sort(whole(rmap));
    for (int i = 0; i < rmap.size(); i++) {
        cout << rmap[i] << endl;
        int cid = map.get(rmap[i]);
        sort(whole(pages[cid]));
        cout << pages[cid][0];
        for (int j = 1; j < pages[cid].size(); j++) {
            cout << " " << pages[cid][j];
        }
        cout << endl;
    }

    return 0;
}
