class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        unordered_map<int, int> freq;
        map<int, set<int>> buckets;
        
        for (int i = 0; i < k; i++) freq[arr[i]]++;
        for (auto& p : freq) buckets[p.second].insert(p.first);
        sum += *buckets.rbegin()->second.begin();
        
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            
            buckets[freq[out]].erase(out);
            if (buckets[freq[out]].empty()) buckets.erase(freq[out]);
            if (--freq[out] > 0) buckets[freq[out]].insert(out);
            else freq.erase(out);
            
            if (freq[in] > 0) {
                buckets[freq[in]].erase(in);
                if (buckets[freq[in]].empty()) buckets.erase(freq[in]);
            }
            buckets[++freq[in]].insert(in);
            
            sum += *buckets.rbegin()->second.begin();
        }
        return sum;
    }
};
