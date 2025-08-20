class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        int left = 0, right = n * m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / m;
            int col = mid % m;
            int midVal = mat[row][col];
            if (midVal == x) return true;
            int leftVal = mat[left / m][left % m];
            int rightVal = mat[right / m][right % m];
            if (leftVal <= midVal) {
                if (leftVal <= x && x < midVal) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {
                if (midVal < x && x <= rightVal) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
