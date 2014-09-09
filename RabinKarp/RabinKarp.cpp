// rolling hash
// hash(str) = ( c_1*b^{m-1} + c_2*b^{m-2} + ... + c_m*b^0 ) mod h
//     where { c_1, c_2, ..., c_m } = str
// hash(str[k+1..k+m]) = (               c_{k+1}*b^{m-1} + c_2*b^{m-2} +           ... + c_{k+m}*b^0 ) mod h
// hash(str[k..k+m-1]) = ( c_k*b^{m-1} + c_{k+1}*b^{m-2} +         ... + c_{k+m-1}*b^0               ) mod h
// hash(str[k+1..k+m]) = ( hash(str[k..k+m-1])*b - str[k]*b^m + str[k+m] ) mod h

namespace RabinKarp {
    typedef unsigned long long hash_t;
    static const hash_t base = 1e9+7; // mod is 2^64 (overflow)

    hash_t rollingHash(const string & s) {
        hash_t a = 0;
        repeat (i,(int)s.length()) a = a * base + s[i];
        return a;
    }

    hash_t baseTo(int n) {
        static map<int,hash_t> memo;
        const map<int,hash_t>::iterator it = memo.find(n);
        if (it != memo.end()) return it->second;
        hash_t x;
        if (n == 0) {
            x = 1;
        } else {
            x = baseTo(n >> 1);
            x *= x;
            if (n & 1) x *= base;
        }
        memo.insert(make_pair(n,x));
        return x;
    }

    hash_t roll(hash_t a, char out, char in, int n) {
        return a * base - out * baseTo(n) + in;
    }
    hash_t pushBack(hash_t a, char c) {
        return a * base + c;
    }
    vector<hash_t> generateTable(const string & s) {
        vector<hash_t> h(s.length()+1);
        h[0] = 0;
        repeat (i,(int)s.length()) h[i+1] = h[i] * base + s[i];
        return h;
    }
    hash_t subhash(const vector<hash_t> & h, int l, int r) {
        return h[r] - h[l] * baseTo(r-l);
    }

    // find sub-string `b' of `a', and return the index or `-1' as not found
    int find(const string & a, const string & b) {
        const int al = a.length();
        const int bl = b.length();
        const hash_t bh = rollingHash(b);
              hash_t ah = rollingHash(a.substr(0,bl));
        repeat (i, al - (bl - 1)) {
            if (ah == bh and a.substr(i,bl) == b) return i; // equal on hash -> verify
            if (i + bl < al) { // there is next loop
                ah = ah * base - a[i] * baseTo(bl) + a[i+bl]; // roll
            }
        }
        return -1;
    }
};
