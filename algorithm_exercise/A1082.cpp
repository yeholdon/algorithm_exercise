#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

char mp[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
char mp1[4][5] = {  "", "Shi", "Bai", "Qian" };
int main() {
	string str;
	cin >> str;
	if (str[0] == '-')
	{
		printf("Fu ");
		str.erase(0, 1);
	}

	int len = str.size();
	int i = 0;
	while (i < len)
	{
		if (str[i] == '0') {
			// ÌØÅÐÖµÎª0
			if (len == 1) {
				printf("ling");
			}
			while (str[i] == '0' && i < len)
			{
				i++;
				if(i == len - 4) printf(" Wan");
			}
			if (i < len) printf(" ling");
		}
		else
		{
			if (i != 0) printf(" ");
			printf("%s", mp[str[i] - '0']);
			if((len - i - 1) % 4 != 0) 
				printf(" %s", mp1[(len - i - 1) % 4]);
			if (len - i > 8) {
				printf(" Yi");
			}
			else if (len - i == 5)
			{
				printf(" Wan");
			}
			i++;
		}
		
	}

	return 0;
}