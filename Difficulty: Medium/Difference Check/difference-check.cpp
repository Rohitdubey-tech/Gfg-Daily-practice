class Solution {
  public:
    int minDifference(vector<string> &arr) {
        vector<int> seconds;
        for (const string& time : arr) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            int s = stoi(time.substr(6, 2));
            int total = h * 3600 + m * 60 + s;
            seconds.push_back(total);
        }
        sort(seconds.begin(), seconds.end());
        int n = seconds.size();
        int minDiff = INT_MAX;
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, seconds[i] - seconds[i - 1]);
        }
        int circularDiff = 86400 - seconds[n - 1] + seconds[0];
        minDiff = min(minDiff, circularDiff);
        return minDiff;
    }
};
