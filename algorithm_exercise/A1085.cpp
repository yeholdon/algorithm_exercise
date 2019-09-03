#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100010;
int main() {
	int p, n;
	int s[maxn]; 
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}
	sort(s, s + n);
	int i = 0, j = 0, maxl = 0;
	while (i < n && j < n)
	{
		while (j < n && (long long)s[i] * p >= s[j])
		{
			maxl = max(maxl, j - i + 1);
			j++;
		}
		i++;
	}
	printf("%d\n", maxl);
	return 0;
}