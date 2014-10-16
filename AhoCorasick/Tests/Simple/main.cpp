#include "../../../Template.cpp"
#include "../../AhoCorasick.cpp"

int main() {
    vector<string> p(0);
    p.push_back("a");
    p.push_back("ab");
    p.push_back("bc");
    p.push_back("bca");
    p.push_back("c");
    p.push_back("caa");
    AhoCorasick matcher(p);
    vector<int> result;
    matcher.match("abccab", result);
    assert ( result.size() == 6 );
    assert ( result[0] == 2 );
    assert ( result[1] == 2 );
    assert ( result[2] == 1 );
    assert ( result[3] == 0 );
    assert ( result[4] == 2 );
    assert ( result[5] == 0 );
    return 0;
}
