/* 繰り返し2乗法 
 * (x ** n) % MODを返す.
 * 計算量 log(n) */
Long ModPow(Long x, Long n, Long Mod) {
    if (n == 0) return 1;
    if (n % 2 == 1) return x * ModPow(x, n - 1, Mod) % Mod;
    Long r = ModPow(x, n / 2, Mod);
    return r * r % Mod;
}
