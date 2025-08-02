class Solution {
public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        int sum = 0, maxLen = 0;
        unordered_map<int, int> firstOccur;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > k) sum += 1;
            else sum -= 1;
            
            if (sum > 0) {
                maxLen = i + 1; 
            } else {
                if (firstOccur.find(sum - 1) != firstOccur.end()) {
                    maxLen = max(maxLen, i - firstOccur[sum - 1]);
                }
            }
                        if (firstOccur.find(sum) == firstOccur.end()) {
                firstOccur[sum] = i;
            }
        }
        return maxLen;
    }
};
