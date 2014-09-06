#include "../../../Template.cpp"
#include "../../RangeSumQuery2.cpp"

int N, Q;
vector<Long> A;
int main() {
    scanf("%d %d\n", &N, &Q);
    A.clear(); A.resize(N, 0);
    char buf[16];
    RangeSumQuery2 rsq2(N);
    repeat(i, N) scanf("%lld", &A[i]); scanf("\n");
    repeat(i, N) rsq2.add(A[i], i, i + 1);
    repeat(q, Q) {
        scanf("%s", buf);
        if (buf[0] == 'Q') {
            int a, b; scanf("%d %d\n", &a, &b);
            a--;
            printf("%lld\n", rsq2.query(a, b));
        } else {
            int a, b, c; scanf("%d %d %d\n", &a, &b, &c);
            a--;
            rsq2.add(c, a, b);
        }
    }
    return 0;
}

