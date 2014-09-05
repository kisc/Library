// rolling hash
// hash(str) = ( c_1*b^{m-1} + c_2*b^{m-2} + ... + c_m*b^0 ) mod h
//     where { c_1, c_2, ..., c_m } = str
// hash(str[k+1..k+m]) = (               c_{k+1}*b^{m-1} + c_2*b^{m-2} +           ... + c_{k+m}*b^0 ) mod h
// hash(str[k..k+m-1]) = ( c_k*b^{m-1} + c_{k+1}*b^{m-2} +         ... + c_{k+m-1}*b^0               ) mod h
// hash(str[k+1..k+m]) = ( hash(str[k..k+m-1])*b - str[k]*b^m + str[k+m] ) mod h

struct RabinKarp {
    static const ULong base = 1e9+7; // mod is 2^64 (overflow)

    // O(n)
    ULong rollingHash(const string & s) const {
        ULong a = 0;
        repeat (i,(int)s.length()) a = a * base + s[i];
        return a;
    }

    // O(1)
    ULong roll(ULong a, char out, char in, ULong base_to_len) const {
        return a * base - out * base_to_len + in;
    }
    ULong baseTo(int n) const {
        ULong c = 1;
        repeat (i,n) c *= base;
        return c;
    }

    // returns the index of `a' and the index of the sub-string in `bs', of -1 * -1.
    // required: the length of strings in `bs' are all the same.
    pair<int,int> findSet(const string & a, const vector<string> & bs) const {
        const int al = a.length();
        const int bn = bs.size();
        if (bs.size() == 0) return make_pair(-1,-1);
        const int bl = bs[0].length();
        vector<ULong> bhs(bn); repeat (i,bn) bhs[i] = rollingHash(bs[i]);
        ULong ah = rollingHash(a.substr(0,bl));
        const ULong base_to_len = baseTo(bl);

        repeat (i, al - (bl - 1)) {
            repeat (j,bn) {
                if (ah == bhs[j] and a.substr(i,bl) == bs[j]) return make_pair(i,j);
            }
            if (i + bl < al) {
                ah = roll(ah, a[i], a[i+bl], base_to_len);
            }
        }
        return make_pair(-1,-1);
    }
};
