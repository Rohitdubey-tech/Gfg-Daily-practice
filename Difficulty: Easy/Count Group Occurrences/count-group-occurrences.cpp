class Solution {
  public:
    int getCount(string &s, int k) {
        // code here
        string p="";
        char ch = '#' ;

        for(char c :s){
            if(ch != c){
                p.push_back(c) ;
                ch = c ;
            }
        }

        map<char,int> freq;
        for(char c : p){
            freq[c]++ ;
        }

        int r=0;
        for(auto &it : freq){
            if(it.second == k)r++ ;
        }

        return r;

    }
};