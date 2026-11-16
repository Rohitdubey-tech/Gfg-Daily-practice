class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int c = k;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] <= c){
                c += 1;
            }
            else{
                break;
            }
        }
        return c;
    }
};