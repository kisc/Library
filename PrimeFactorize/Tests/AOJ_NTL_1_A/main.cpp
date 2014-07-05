#include "../../../Template.cpp"
#include "../../PrimeFactorize.cpp"

int main() {
    Long n; cin >> n;
    typedef map<Long, int> M;
    M P = PrimeFactorize(n);
    cout << n << ":";
    for (M::iterator it = P.begin(); it != P.end(); it++) {
        for (int i = 0; i < it->second; i++) {
            cout << " " << it->first;
        }
    }
    cout << endl;
    return 0;
}
