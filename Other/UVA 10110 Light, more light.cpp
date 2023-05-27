//Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1051
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
