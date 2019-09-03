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


/*���Ե�3����
������
n = 2*3*4*5*3*7
���⵽2*3*4*5�󣬷���6���У���ǰ��ĳ���Ϊ4������㷨ֱ�Ӵ�7��ʼ����
���������3��ʼ3*4*5*6*7�ǿ��еģ�����ʵ�ʺ������������Ӧ��ÿ��ֻ��һ����
*/