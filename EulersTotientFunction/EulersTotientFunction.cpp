/* オイラーのφ関数 
 * 正の整数 n について、1 から n までの自然数のうち n と互いに素なものの個数を求める */

// ここにPrimeFactorizeを展開
Long Pow(Long x, Long n) {
    Long Ret = 1;
    for (int i = 0; i < n; i++) Ret *= x;
    return Ret;
}
Long EulersTotientFunction(Long n) {
    typedef map<Long, int> M;
    M Factor = PrimeFactorize(n);
    Long Ret = 1;
    for (M::iterator it = Factor.begin(); it != Factor.end(); it++) {
        Ret *= Pow(it->first, it->second) - Pow(it->first, it->second - 1);
    }
    return Ret;
}
