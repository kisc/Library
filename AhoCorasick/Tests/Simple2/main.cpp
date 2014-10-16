#include "../../../Template.cpp"
#include "../../AhoCorasick.cpp"

int main() {
    vector<string> p(100);
    string s = "a";
    repeat (i,100) {
        p[i] = s;
        s += 'a';
    }
    AhoCorasick matcher(p);
    vector<int> result;
    matcher.match(s, result);
    repeat (i,100) assert (result[i] == 101-i);
    return 0;
}
