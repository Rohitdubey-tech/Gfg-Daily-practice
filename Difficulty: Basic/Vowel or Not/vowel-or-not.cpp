class Solution {
  public:
    string isVowel(char c) {
        // code here
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            return "YES";
        return "NO";
    }
};