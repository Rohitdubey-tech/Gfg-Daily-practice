class Solution {
  public:
    int getMinimumDays(string &s, vector<int> &p) {
            // code here
            int n = s.size();
            if(n==1)return 0;
            int cnt = 0 ;
            for(int i=0;i<n-1;i++)if(s[i]==s[i+1])cnt++;
            for(int i=0;i<n;i++){
                // cout << cnt << " ";
                if(cnt==0)return i;
                if(p[i]==0){
                    if(s[0]==s[1] && s[0]!='?')cnt--;
                    s[0]='?';
                }
                else if(p[i]==n-1){
                    if(s[n-1]==s[n-2] && s[n-1]!='?')cnt--;
                    s[n-1]='?';
                }
                else{
                    if(s[p[i]]==s[p[i]+1] && s[p[i]]!='?')cnt--;
                    if(s[p[i]]==s[p[i]-1] && s[p[i]]!='?')cnt--;
                    s[p[i]]='?';
                }

            }
            // cout << endl;
            return n;
        }
};
