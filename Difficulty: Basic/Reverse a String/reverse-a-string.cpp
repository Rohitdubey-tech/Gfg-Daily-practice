// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        int i=0; 
        int j=s.length() - 1;
        while(i<j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};
