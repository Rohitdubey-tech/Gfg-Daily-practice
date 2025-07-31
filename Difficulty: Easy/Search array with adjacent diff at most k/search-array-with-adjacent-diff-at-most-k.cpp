// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        // code here
    //     if(arr[i]==x)
    //         return i;
    //     return -1;
    // }
    int n = arr.size();
        int i = 0;
        
        while (i < n) {
            if (arr[i] == x)
                return i;
                        int jump = max(1, abs(arr[i] - x) / k);
            i += jump;
        }
        return -1;
    }
    
};