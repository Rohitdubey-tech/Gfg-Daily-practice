class Solution {
public:
    bool canMakeBouquets(vector<int>& arr, int m, int k, int day) {
        int bouquets = 0, flowers = 0;
        for (int bloomDay : arr) {
            if (bloomDay <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }

    // Function name + parameter order matches Driver.cpp
    int minDaysBloom(vector<int>& arr, int k, int m) {
        long long total = 1LL * m * k;
        if (arr.size() < total) return -1;

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canMakeBouquets(arr, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
