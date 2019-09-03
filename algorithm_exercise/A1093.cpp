#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	// ÊäÈë
	string str;
	cin >> str;
	int i = 0, j = str.size() - 1;
	int cur_p = 0, cur_t = 0;
	unordered_map<int, int> ap, at;
	int length = str.size();
	for (int i = 0; i < length; i++)
	{
		if (str[i] == 'P') {
			cur_p++;
		}
		else if (str[i] == 'A') {
			ap[i] = cur_p;
		}

		if (str[length - 1 - i] == 'T') {
			cur_t++;
		}
		else if (str[length - 1 - i] == 'A')
		{
			at[length - 1 - i] = cur_t;
		}
	}

	int sum = 0;
	unordered_map<int, int>::iterator it;
	for (it = ap.begin(); it != ap.end(); it++)
	{
		sum = (sum + it->second * at[it->first]) % 1000000007;
	}
	printf("%d\n", sum);
	return 0;
}