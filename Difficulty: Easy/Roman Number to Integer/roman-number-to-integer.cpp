class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char, int> value ={
            {'I',1}, {'V', 5},{'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        for(int i=0; i<s.size(); i++){
            int current = value[s[i]];
            int next = (i+1<s.size()) ? value[s[i+1]] : 0;
            if(current < next){
                result -= current;
            }
            else{
                result += current;
            }
        }
        return result;
    }
};