/*
By Soliman Elhassanein
TC: O(2n)
MC: O(26)
*/
  

class Solution {
public:
    string smallestSubsequence(string s) {
        string result = "";
        int last[26];

        for(int i = 0; i<s.size(); i++){
            last[s[i] - 'a'] = i;
        }

        for(int i = 0; i<s.size(); i++){
            if (result.find(s[i]) == string::npos) {
                while (result.size() && i < last[result.back() - 'a'] && s[i] < result.back())
                    result.pop_back();

                result.push_back(s[i]);
            }
        }
        return result;
    }
};
