//TC: O(n)
//MC: O(n)
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{

	int old = 0, mod, step;
	cin >> step >> mod;
	bool flag = false;

	vector<bool>* check = new vector<bool>(mod,false);

	for (int i = 0; i < mod; i++)
	{
		if ((*check)[(old + step) % mod] == true)
		{
			flag = true;
			break;
		}
		else
		{
			(*check)[(old + step) % mod] = true;
			old = (old + step) % mod;
		}
	}

	if (flag)
		  cout << step << ' ' << mod <<  ' ' << "Bad choice";
	else
		cout << step << ' ' << mod << ' ' << "Good choice";

	return 0;
}
