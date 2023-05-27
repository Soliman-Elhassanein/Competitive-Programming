//TC: O(n)
//MC: O(1)
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, c;
	long long result;

	cin >> n >> m >> c;

	while (n||m||c) {

		if (c)
			result = ceil((n - 7) * (m - 7) / 2.0);
		else
			result = floor((n - 7) * (m - 7) / 2.0);
		
		cout << result << endl;

		cin >> n >> m >> c;
	}
  
	return 0;
}
