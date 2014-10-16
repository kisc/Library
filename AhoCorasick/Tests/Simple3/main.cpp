#include "../../../Template.cpp"
#include "../../AhoCorasick.cpp"

int main() {
    vector<string> p;
    p.push_back("a");
    p.push_back("ab");
    p.push_back("bc");
    AhoCorasick matcher(p);

    vector<string> q;
    q.push_back("bca");
    q.push_back("c");
    q.push_back("caa");
    AhoCorasick matcher2 = AhoCorasick(q);
    vector<int> result;
    matcher2.match("abccab", result);

    return 0; // SIGSEGV in the dtor
}
