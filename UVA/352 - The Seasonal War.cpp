//29-May-2023

//TC: O(n^2)
//MC: O(n^2)

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>

using namespace std;


void DepthFirstSearch(vector<vector<char>> &image, vector<vector<bool>> &visited, int dimension, int row, int col) {
    int DeltaRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int DeltaCol[8] = { -1, 0, 1, -1, 1, -1, 0, 1};

    int NewRow;
    int NewCol;

    for (int i = 0; i < 8; i++) {

        NewRow = row + DeltaRow[i];
        NewCol = col + DeltaCol[i];

        if (NewRow < 0 || NewRow >= dimension || NewCol < 0 || NewCol >= dimension)
            continue;

        if (image[NewRow][NewCol] == '1' && !visited[NewRow][NewCol]) {
            visited[NewRow][NewCol] = true;
            DepthFirstSearch(image, visited, dimension, NewRow, NewCol);
        }

        

    }
}

int WarEagles(vector<vector<char>> image, int dimension) {
    int counter = 0;
    vector<vector<bool>> visited(dimension, vector<bool>(dimension, false));

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (image[i][j] == '1' && !visited[i][j]) {
                counter++;
                visited[i][j] = true;
                DepthFirstSearch(image, visited, dimension, i, j);
                
            }
        }
    }

    return counter;
}


int main() {
    
    int dimension;
    int NumberOfWarEagles;
    cin >> dimension;

    vector<vector<char>> image(dimension, vector<char>(dimension));

    for (auto &row : image) {
        for (auto &col : row) {
            cin >> col;
        }
    }

    NumberOfWarEagles = WarEagles(image, dimension);

    cout << NumberOfWarEagles;
    
    return 0;
}
