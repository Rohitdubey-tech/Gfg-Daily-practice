class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int l = 0, zeros = 0, maxLen = 0;
        for (int r = 0; r < arr.size(); r++) {
            zeros += (arr[r] == 0);
            while (zeros > k) zeros -= (arr[l++] == 0);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};