//01-Jun-2023
//TC: O(2*n^2)
//MC: O(2*n^2)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>

using namespace std;


void DepthFirstSearch(int Dimensions, vector<vector<char>>& Grid, vector<vector<bool>>& Visited, pair<int,int> Start) {

    int DeltaX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int DeltaY[] = { -1, 0, 1, -1, 1, -1, 0 , 1 };

    int NewRow;
    int NewCol;

    for (int i = 0; i < 8; i++) {
        NewRow = Start.first + DeltaX[i];
        NewCol = Start.second + DeltaY[i];

        if (NewRow < 0 || NewRow >= Dimensions || NewCol < 0 || NewCol >= Dimensions)
            continue;

        if (Grid[NewRow][NewCol] == 'x' && Visited[NewRow][NewCol] == false) {
            Visited[NewRow][NewCol] = true;

            Start.first = NewRow;
            Start.second = NewCol;
            
            DepthFirstSearch(Dimensions, Grid, Visited, Start);

            Start.first -= DeltaX[i];
            Start.second -= DeltaY[i];

       }
    }

}

int CountShips(int Dimensions, vector<vector<char>>& Grid) {
    
    vector<vector<bool>> Visited(Dimensions, vector<bool>(Dimensions, false));
    int counter = 0;
    pair<int, int> Start;

    for (int i = 0; i < Dimensions; i++) {
        for (int j = 0; j < Dimensions; j++) {
            if (Grid[i][j] == 'x' && Visited[i][j] == false) {
                Visited[i][j] = true;
                Start = { i,j };
                DepthFirstSearch(Dimensions, Grid, Visited, Start);
                counter++;
            }
        }
    }

    return counter;
}

int main() {
    
    int TestCases, Dimensions, NumberOfShips, counter = 0;
    cin >> TestCases;

    while (TestCases) {
        TestCases--;
        counter++;
        
        cin >> Dimensions;

        vector<vector<char>> Grid(Dimensions, vector<char>(Dimensions));
         
        for (int i = 0; i < Dimensions; i++) {
            for (int j = 0; j < Dimensions; j++) {
                cin >> Grid[i][j];
            }
        }

        NumberOfShips = CountShips(Dimensions, Grid);

        
        cout << "Case " << counter << ": " << NumberOfShips << endl;
        
    }
    
    return 0;
}
