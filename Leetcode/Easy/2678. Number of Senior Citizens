class Solution {
public:
    int countSeniors(vector<string>& details) {
        int counter = 0;
        int temp = 0;
        for(int i = 0; i < details.size(); i++)
        {
            
            temp = (int(details[i][11])-'0')*10 + int(details[i][12])-'0';
            if(temp >60)
            {
                counter++;
            }
        }

        return counter;
    }
};
