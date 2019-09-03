#include <cstdio>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
unordered_map<char, int> mp;

int main() {
	string text, pattern;
	cin >> text >> pattern;
	//transform(text.begin(), text.end(), text.begin(), ::toupper);
	//transform(pattern.begin(), pattern.end(), pattern.begin(), ::toupper);
	//int i = 0, j = 0;
	int alen = text.size(), blen = pattern.size();


	for (int i = 0; i < alen; i++)
	{
		int j = 0;
		for (j = 0; j < blen; j++)
		{
			if (toupper(text[i]) == toupper(pattern[j])) {

				break;
			}
		}

		if (j == blen && mp[toupper(text[i])] == 0) {
			printf("%c", toupper(text[i]));
			mp[toupper(text[i])]++;
		}
	}


	return 0;
}