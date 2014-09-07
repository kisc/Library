#include "../../../Template.cpp"
#include "../../Matrix.cpp"

Matrix I(Long N) {
    Matrix Ret(N, N);
    repeat(i, N) Ret[i][i] = 1;
    return Ret;
}

const Long MOD = 1e4;

void operator%=(Matrix &A, Long x) {
    repeat(i, A.H) repeat(j, A.W)
        A[i][j] %= x;
}

Matrix pow(Matrix A, Long n) {
    if (n == 0) return I(A.H);
    Matrix Ret(A.H, A.W);
    if (n % 2 == 1) {
        Ret = A * pow(A, n - 1);
    } else {
        A = A * A; A %= MOD;
        Ret = pow(A, n / 2);
    }
    Ret %= MOD;
    return Ret;
}

int main() {
    int N;
    while (scanf("%d\n", &N), N >= 0) {
        //printf("N: %d\n", N);
        Matrix A(2, 2);
        A[0][0] = 1; A[0][1] = 1;
        A[1][0] = 1; A[1][1] = 0;
        A = pow(A, N);
        printf("%lld\n", A[1][0]);
    }
    return 0;
}
