//TC: O(n)
//MC: O(n)

#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	string output = "";

	for (int i = 0; i < n; i++)
	{
		output += ('a' + i % k);
	}

	cout << output;

	return 0;
}
