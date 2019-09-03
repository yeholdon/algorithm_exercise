#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	unordered_map<char, int> mp, mp_tar;
	int sum = 0, del = 0;
	string str, tar_str;
	cin >> str >> tar_str;
	for (int i = 0; i < str.size(); i++) {
		mp[str[i]]++;
	}
	for (int i = 0; i < tar_str.size(); i++)
	{
		mp_tar[tar_str[i]]++;
	}
	bool flag = true;
	unordered_map<char, int>::iterator it;
	for ( it = mp_tar.begin(); it != mp_tar.end() ; it++)
	{
		char c = it->first;
		if (mp[c] < it->second) {
			flag = false;
			del += it->second - mp[c];
		}
	}

	if (flag) {
		printf("Yes %d\n", str.size() - tar_str.size());
	}
	else
	{
		printf("No %d\n", del);
	}
	return 0;
}