//TC: O(n^2)
//MC: O(n)
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
	int n,temp1,temp2, result = 0;
	cin >> n;
 
	vector<vector<int>> colors;
 
	for (int i = 0; i < n; i++)
	{
		cin >> temp1 >> temp2;
		vector<int> temp = { temp1, temp2 };
		colors.push_back(temp);
	}
 
	for (int i =0; i<n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (colors[i][0] == colors[j][1])
					result++;
			}
		}
	}
	
	cout << result;
}
