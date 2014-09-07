/* 行列ライブラリ
 *
 * modをとるとか数値をLong以外の型にするとか問題に合わせて適宜変更して使う.
 * かけ算の処理をバグらせそうなのでライブラリに追加. */

struct Matrix : vector< vector<Long> > {
    int H, W;
    Matrix(int H, int W) : H(H), W(W), vector< vector<Long> >(H, vector<Long>(W, 0)) {}
};

Matrix operator+(const Matrix &A, const Matrix &B) {
    //assert(A.H == B.H && A.W == B.W);
    Matrix Ret(A.H, A.W);
    repeat(i, A.H) {
        repeat(j, A.W) {
            Ret[i][j] = A[i][j] + B[i][j];
            // Ret[i][j] %= MOD; (modをとるとき)
        }
    }
    return Ret;
}

Matrix operator*(const Matrix &A, const Matrix &B) {
    //assert(A.W == B.H);
    Matrix Ret(A.H, B.W);
    repeat(i, A.H) {
        repeat(j, B.W) {
            repeat(k, A.W) {
                Ret[i][j] += A[i][k] * B[k][j];
                // Ret[i][j] %= MOD; (modをとるとき)
            }
        }
    }
    return Ret;
}
