#include "../../../Template.cpp"
#include "../../ModPow.cpp"

int main() {
    Long Mod = Long(1e9 + 7);
    Long m, n; cin >> m >> n;
    cout << ModPow(m, n, Mod) << endl;
    return 0;
}
