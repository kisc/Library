#include "../../../Template.cpp"
#include "../../../PrimeFactorize/PrimeFactorize.cpp"
#include "../../EulersTotientFunction.cpp"

int main() {
    Long n; cin >> n;
    cout << EulersTotientFunction(n) << endl;
    return 0;
}
