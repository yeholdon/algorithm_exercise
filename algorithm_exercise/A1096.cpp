#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;

int main() {
	LL n;
	LL maxl = 0, cntl = 0, last;
	scanf("%lld", &n);
	LL tmp = n;
	LL i = 2, sqr;
	sqr = (LL)sqrt(1.0 * n);
	while (i <= sqr)
	{
		int j = i;
		while (1)
		{
			if (tmp == 1) break;

			if (tmp % j == 0) {
				cntl++;
				tmp /= j;
			}
			else {
				cntl = 0;
				tmp = n;
				break;
			}

			if (cntl > maxl) {
				maxl = cntl;
				last = j;
			}
			j++;
		}

		i++;

	}

	if (maxl == 0) {
		printf("1\n%d\n", n);
	}
	else
	{
		printf("%d\n", maxl);
		for (LL i = last - maxl + 1; i <= last; i++)
		{
			if (i != last - maxl + 1) printf("*");
			printf("%d", i);
		}
	}
	return 0;
}


/*测试点3不过
反例：
n = 2*3*4*5*3*7
当解到2*3*4*5后，发现6不行，当前最长的长度为4这里的算法直接从7开始往后。
但是如果从3开始3*4*5*6*7是可行的，所以实际忽略了这种情况应该每次只走一步。
*/