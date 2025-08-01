class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int countBalanced(vector<string>& arr) {
        // Prefix balance: vowels - consonants
        unordered_map<int, int> freq;
        freq[0] = 1;  // balance 0 has occurred once (empty prefix)

        int balance = 0;
        int result = 0;

        for (const string& word : arr) {
            int v = 0, c = 0;

            // Count vowels and consonants in current word
            for (char ch : word) {
                if (isVowel(ch)) v++;
                else c++;
            }

            balance += (v - c);

            // If this balance was seen before, it forms a balanced subarray
            result += freq[balance];

            // Record this balance
            freq[balance]++;
        }

        return result;
    }
};