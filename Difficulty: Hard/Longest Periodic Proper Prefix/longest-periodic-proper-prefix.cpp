// class Solution {
//   public:
//     int getLongestPrefix(string &s) {
//         int n = s.size();
        
//         for (int len = n - 1; len >= 1; len--) {
//             bool ok = true;
//             for (int i = 0; i < n; i++) {
//                 if (s[i] != s[i % len]) {
//                     ok = false;
//                     break;
//                 }
//             }
//             if (ok) return len; // found the longest periodic proper prefix
//         }
        
//         return -1;
//     }
// };

class Solution {
  public:
    vector<int> zFunction(const string &s) {
        int n = s.size();
        vector<int> z(n, 0);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }
    
    int getLongestPrefix(string &s) {
        int n = s.size();
        vector<int> z = zFunction(s);
        for (int len = n - 1; len >= 1; len--) {
            if (z[len] >= n - len) return len;
        }
        return -1;
    }
};
