class Solution {
public:
    int countTriangles(vector<int>& a) {
        sort(a.begin(), a.end());
        int c = 0, n = a.size();
        for (int k = n - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (a[i] + a[j] > a[k]) {
                    c += j - i;
                    --j;
                } else ++i;
            }
        }
        return c;
    }
};