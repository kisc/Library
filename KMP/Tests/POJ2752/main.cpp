#include "../../../Template.cpp"
#include "../../KMP.cpp"

const int X = 400005;

ostream& operator<<(ostream &os, const vector<int> &vs) {
    os << vs[0];
    for (int i = 1; i < vs.size(); i++) os << " " << vs[i];
    return os;
}

int main() {
    string s;
    while (cin >> s) {
        vector<int> Ans;
        KMP K(s);
        int i = s.size();
        while (i > 0) {
            Ans.push_back(i);
            i = K.PMA[i];
        }
        sort(whole(Ans));
        cout << Ans << endl;
    }
    return 0;
}
