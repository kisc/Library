/* Aho Corasick法による文字列探索 */

/* 
 * 文字集合はそれを表す数が連続していないといけない.
 *   - 'a' ~ 'z',
 *   - 'A' ~ 'Z',
 *   - '0' ~ '9'
 *   - ASCII 0 ~ 255
 * など.
 *
 * 「'a' ~ 'z'と'A' ~ 'Z'」のようなものは使えない. そういうときはASCII全部を使う.
 *
 * */
const static int SIGMA = 256;         // 使用する文字集合のサイズ
const static int FIRST_ALPHABET = 0;  // 最初の文字

/* オートマトン用のTrie. 
 * Aho Corasickの実装の都合でデストラクタがすこし変な実装になっている. 
 * 流用するときは注意. */
struct Trie {
    static Trie* root;
    Trie* fail;
    Trie** next;
    vector<int> accept;
    Trie() {
        next = new Trie*[SIGMA];
        for (int i = 0; i < SIGMA; i++) next[i] = NULL;
    }
    ~Trie() {
        for (int i = 0; i < SIGMA; i++) {
            if (next[i] == root || next[i] == NULL) continue;
            delete next[i];
        }
        delete[] next;
    }
};
Trie* Trie::root;

/* 実用上問題にはならないが, instanceを複数同時に作るとSEGVする.
 * つまり
 * while (...) { AhoCorasick a(...); ... }
 * は良いが,
 * AhoCorasick a(...); while (...) { a = AhoCorasick(...); ... }
 * は落ちる. */
struct AhoCorasick {
    Trie* PMA;
    vector<string> patterns;
    ~AhoCorasick() { delete PMA; }
    AhoCorasick(vector<string> patterns) : patterns(patterns) {
        PMA = new Trie;
        Trie::root = PMA;
        for (int i = 0; i < patterns.size(); i++) {
            Trie* t = PMA;
            string pattern = patterns[i];
            for (int j = 0; j < pattern.size(); j++) {
                int c = pattern[j] - FIRST_ALPHABET;
                if (t->next[c] == NULL) t->next[c] = new Trie;
                t = t->next[c];
            }
            t->accept.push_back(i);
        }
        queue<Trie*> Q;
        for (int i = 0; i < SIGMA; i++) {
            if (PMA->next[i] == NULL) {
                PMA->next[i] = PMA;
            } else {
                PMA->next[i]->fail = PMA;
                Q.push(PMA->next[i]);
            }
        }
        while (!Q.empty()) {
            Trie* t = Q.front(); Q.pop();
            for (int c = 0; c < SIGMA; c++) {
                if (t->next[c] == NULL) continue;
                Q.push(t->next[c]);
                Trie* r = t->fail;
                while (r->next[c] == NULL) r = r->fail;
                t->next[c]->fail = r->next[c];
                vector<int>& accept = t->next[c]->accept;
                accept.insert(accept.end(), whole(r->next[c]->accept));
            }
        }
    }
    // sに各パターンが何回マッチするかをresultに入れる
    void match(const string& s, vector<int>& result) {
        result.clear(); result.resize(patterns.size(), 0);
        Trie* v = PMA;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - FIRST_ALPHABET;
            while (v->next[c] == NULL) v  = v->fail;
            v = v->next[c];
            for (int j = 0; j < v->accept.size(); j++) {
                result[ v->accept[j] ]++;                 // v->accept[j]番目のパターンp が sに[i - len(p) + 1, i]でマッチ 
            }
        }
    }
};
