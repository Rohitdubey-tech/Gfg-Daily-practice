class Solution {
  public:
    bool findPattern(string& s) {
        // code here

        int n = s.length();

        int counter=0;


         int i=0;

         while(i<n){

            if(s[i]=='x'){
                while(s[i] =='x'){
                 counter++;
                  i++;
                }
            } 


            if(s[i]=='y'){
                while(s[i]=='y'){
                   counter--;
                   i++;

                }
            }

            if(counter!=0){
                return false;
            }



        }

        return true;


    }
};