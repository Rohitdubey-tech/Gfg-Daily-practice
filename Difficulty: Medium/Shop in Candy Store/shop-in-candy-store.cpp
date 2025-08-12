class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size();
        int minCost = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            minCost += prices[i];
            i++;
            j -= k; 
        }
        int maxCost = 0;
        i = n - 1, j = 0;
        while (j <= i) {
            maxCost += prices[i];
            i--;
            j += k; 
        }
        return {minCost, maxCost};
    }
};
