#include "../../../Template.cpp"
#include "../../KMP.cpp"

const int w = 1e4 + 1;
const int t = 1e6 + 1;
char W[w], T[t];

int main() {
    int N; scanf("%d\n", &N);
    repeat(_, N) {
        scanf("%s", W);
        scanf("%s", T);
        cout << KMP(W).match(T) << endl;
    }
    return 0;
}
