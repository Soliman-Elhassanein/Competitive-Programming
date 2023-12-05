/*
Link: https://codeforces.com/contest/716/problem/B

By Soliman
Date: 4 Dec 2023

TC: O(n)
MC: O(n)
*/


// Improving input/output efficiency
#define IOS std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	IOS;
	string str;
	bool check[26] = { false }, flag;
	cin >> str;
	queue<int> remained;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (i + 25 > str.size()) { cout << -1; break; }
		flag = true;
		fill(check, check + 25, false);
		for (int j = i; j < i + 26; j++) {
			if (str[j] != '?') {
				if (check[str[j] - 'A']) {
					flag = false;
					break;
				}
				else
					check[str[j] - 'A'] = true;
			}
		}
		if (!flag) { continue; }

		for (int j = 0; j < 26; j++) {
			if (!check[j])
				remained.push(j);
		}

		for (int j = i; j < i + 26; j++) {
			if (str[j] == '?') {
				str[j] = 'A' + remained.front();
				remained.pop();
			}
		}
		for (auto& i : str)
			if (i == '?')
				i = 'A';

		cout << str;
		break;
	}

	return 0;

}

