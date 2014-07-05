/* 素因数分解.
 * 返り値: (素因数, 指数)のmap */
map<Long, int> PrimeFactorize(Long n) {
    map<Long, int> Ret;
    for (Long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            Ret[i]++;
            n /= i;
        }
    }
    if (n != 1) Ret[n]++;
    return Ret;
}
