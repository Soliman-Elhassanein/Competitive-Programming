#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int k, r,counter = 1;
	cin >> k >> r;

	while (1)
	{
		if ((k * counter) % 10 == r || (k * counter) % 10 == 0)
			break;
		else
			counter++;
	}
	cout << counter;
}
