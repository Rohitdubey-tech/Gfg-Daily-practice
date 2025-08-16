class Solution {
  public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q,
                          vector<int> queries[]) {
        vector<int> ans;
        vector<pair<int,int>> dir1 = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1},  {1,0},  {1,1}
        };
        vector<pair<int,int>> dir2 = {
            {-2,-2}, {-2,-1}, {-2,0}, {-2,1}, {-2,2},
            {-1,-2},                   {-1,2},
            {0,-2},                     {0,2},
            {1,-2},                     {1,2},
            {2,-2}, {2,-1}, {2,0}, {2,1}, {2,2}
        };
        for (int k = 0; k < q; k++) {
            int type = queries[k][0];
            int i = queries[k][1];
            int j = queries[k][2];
            long long sum = 0;
            if (type == 1) {
                for (auto &d : dir1) {
                    int x = i + d.first, y = j + d.second;
                    if (x >= 0 && x < n && y >= 0 && y < m)
                        sum += mat[x][y];
                }
            } else { 
                for (auto &d : dir2) {
                    int x = i + d.first, y = j + d.second;
                    if (x >= 0 && x < n && y >= 0 && y < m)
                        sum += mat[x][y];
                }
            }
            ans.push_back((int)sum);
        }
        return ans;
    }
};
