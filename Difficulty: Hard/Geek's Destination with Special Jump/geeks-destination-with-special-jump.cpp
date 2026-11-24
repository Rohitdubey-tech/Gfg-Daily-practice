class Solution {
    using ll = long long;
    static const ll MOD = 1000000007LL;

    ll ceilDiv(ll x, ll y) {
        if (x >= 0)
            return (x + y - 1) / y;
        return x / y;
    }

    ll getTime(ll x, ll a, ll b) {
        ll c = a - b;
        ll k = max(0LL, ceilDiv(x - a, c));
        return x + 2 * b * k;
    }

    ll sumK(ll L, ll R, ll a, ll c) {
        if (L > R) return 0;

        ll ans = 0;

        for (ll rem = 0; rem < c; rem++) {
            ll first = L + (rem - L % c + c) % c;

            if (first > R) continue;

            ll cnt = (R - first) / c + 1;
            ll t = (first - rem) / c;

            ll offset = ceilDiv(rem - a, c);

            ll sumT = cnt * (2 * t + cnt - 1) / 2;

            ans += sumT + cnt * offset;
        }

        return ans;
    }

public:
    int minTime(int a, int b, int d, int l, int r) {
        ll normal = getTime(d, a, b);

        ll L = d - r;
        ll R = d - l;

        ll low = L, high = R;
        ll p = L - 1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (1 + getTime(mid, a, b) <= normal) {
                p = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        ll ans = 0;

        if (L <= p) {
            ll cnt = p - L + 1;

            ll sumX = (L + p) * cnt / 2;

            ll sumCycles = sumK(max(L, (ll)a + 1),
                                p, a, a - b);

            ans += cnt + sumX + 2LL * b * sumCycles;
        }

        if (p < R) {
            ll cnt = R - max(L, p + 1) + 1;
            ans += cnt * normal;
        }

        return ans % MOD;
    }
};
