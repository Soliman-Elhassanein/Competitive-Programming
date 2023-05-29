//TC: O(n)
//MC: O(1)
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned int n, temp, check;

	cin >> temp;

	do
	{
		check = sqrt(temp);

		if (check * check == temp)
			cout << "yes";
		else
			cout << "no";

		cin >> temp;

	} while (temp);

	return 0;
}
