class Solution {
public:
    long long numberOfWays(long long N) {
        if (N <= 2) return N;
        long long a = 1, b = 2, c;
        for (long long i = 3; i <= N; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
