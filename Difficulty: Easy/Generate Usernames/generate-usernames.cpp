class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {
        // code here
        unordered_set<string> assigned(arr.begin() , arr.end());
        unordered_map<string, int> nameCount;
        unordered_set<string> seen;
        vector<string>result;


        for(const string& s : arr){
            if(seen.find(s) == seen.end()){
                seen.insert(s);
                result.push_back(s);
                if(nameCount.find(s) == nameCount.end()){
                    nameCount[s] = 0;
                }
            }

            else {
                int k = nameCount[s];
                string newName;


                do{
                    k++;
                    newName = s + to_string(k);
                }

                while(assigned.find(newName) != assigned.end());

                nameCount[s] = k;
                assigned.insert(newName);
                result.push_back(newName);
            }
        }

        return result;
    }
};