// User function template for C++
class Solution {
  public:
    bool allZero(vector<int>& counter){
        for(int &i : counter){
            if(i!=0) 
                return false;
        }
        return true;
    }
    int search(string &pat, string &txt) {
        // code here
        int n = txt.size();
        if(txt.size()<pat.size()) return 0;
        vector<int> counter(26, 0);
        for(int i=0; i<pat.size(); i++){
            counter[pat[i]-'a']++;
        }
        int i=0, j=0;
        int res = 0;
        int k = pat.size();
        while(j<n){
            counter[txt[j]-'a']--;
            if(j-i+1 == k){
                if(allZero(counter)){
                    res++;
                }
                counter[txt[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};