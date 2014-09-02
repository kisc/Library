/* Trieはどうとでも応用できるデータ構造であるために汎用的な実装はしない 
 * Mapの実装だけおいとく */

/* TrieによるMap(string -> int)の実装*/
struct TrieMap {
    int value;
    TrieMap* children[26];
    void set(const string& s, int value, int index = 0) {
        if (index == s.size()) {
            this->value = value;
            return;
        }
        if (!children[ s[index] - 'a' ]) {
            children[ s[index] - 'a' ] = new TrieMap();
        }
        children[ s[index] - 'a' ]->set(s, value, index + 1);
    } 
    int get(const string& s, int index = 0) {
        if (index == s.size()) return value;
        if (!children[ s[index] - 'a' ]) return -1; // NOT FOUND
        return children[ s[index] - 'a']->get(s, index + 1);
    }
    bool find(const string& s) {
        return get(s) != -1;
    }
    TrieMap() {
        value = -1;
        for (int i = 0; i < 26; i++) children[i] = NULL;
    }
    ~TrieMap() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                delete(children[i]);
            }
        }
    }
    void print(int lmargin = 0) {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                cout << string(lmargin, ' ');
                cout << char(i + 'a');
                if (children[i]->value >= 0) cout << " -> " << children[i]->value;
                cout << endl;
                children[i]->print(lmargin + 2);
            }
        }
    }
};

