//30-May-2023
//TC: O(n*m)
//MC: O(n*m)

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>

using namespace std;

void DepthFirstSearch(vector<int>& start, vector<vector<char>>& stones, int Length, int Width, string word, int Location, vector<string>& PathWords) {

    int DeltaX[] = { 0, -1, 0 };
    int DeltaY[] = { -1, 0, 1 };

    for (int i = 0; i < 3; i++) {
        int NewRow = DeltaX[i] + start[0];
        int NewCol = DeltaY[i] + start[1];

        if (NewRow < 0 || NewRow >= Length || NewCol < 0 || NewCol >= Width)
            continue;

        if (stones[NewRow][NewCol] == word[Location])
        {
            start[0] = NewRow;
            start[1] = NewCol;

            if (i == 0)
                PathWords.push_back("left");
            else if (i == 1)
                PathWords.push_back("forth");
            else if (i == 2)
                PathWords.push_back("right");

            break;
        }
    }
}


void FindPath(vector<int>& start, vector<vector<char>>& stones, int Length, int Width, vector<string>& PathWords) {

    string word = "IEHOVA#";
    int Location = 0;

    while (Location != 8)
    {
        DepthFirstSearch(start, stones, Length, Width, word, Location, PathWords);
        Location++;
    }
}


int main() {
    
    int NumberOfTestCases, Length, Width;
    cin >> NumberOfTestCases;

    vector<int> start(2);

    while (NumberOfTestCases) {
        NumberOfTestCases--;

        cin >> Length >> Width;

        vector<vector<char>> stones(Length, vector<char>(Width));
        vector<string> PathWords;

        for (int i = 0; i < Length; i++) {
            for (int j = 0; j < Width; j++) {
                cin >> stones[i][j];

                if (stones[i][j] == '@') {
                    start[0] = i;
                    start[1] = j;
                }
            }
        }

        FindPath(start, stones, Length, Width, PathWords);

        for (auto word : PathWords)
            cout << word << " ";

        cout << endl;


    }
    
    return 0;
}
