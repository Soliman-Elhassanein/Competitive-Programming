class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;
        char temp;
        for(int i = 0; i<word.length();i++)
        {
            if(word[i] == ch)
            {
                index = i;
                cout << index;
                break;
            }
        }

        for(int i = 0a; i<=(index/2); i++)
        {
            
            temp = word[word.length()-(word.length()-index)-i];
            word[word.length()-(word.length()-index)-i] = word[i];
            word[i] = temp;
        }

        return word;
    }
};
