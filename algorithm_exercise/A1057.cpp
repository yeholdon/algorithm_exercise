/*分块法
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int maxb = 317;
const int maxn = 100010;
int block[maxb];
int hashTable[maxn]; // 存对应元素的的数量
int main() {
	// 初始化
	memset(block, 0, sizeof(block));
	memset(hashTable, 0, sizeof(hashTable));
	// 输入
	int n, cnt = 0, e;
	char op[12];
	stack<int> st;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", op);
		if (!strcmp(op, "PeekMedian")) {
			
			if (cnt == 0) {
				printf("Invalid\n");
			}
			else {
				int median;
				if ((cnt & 1) == 0) {
					median = cnt >> 1;
				}
				else
				{
					median = (cnt + 1) >> 1;
				}
				int tmp = 0;
				for (int j = 0; j < maxb; j++)
				{
					if(tmp + block[j] < median) {
						tmp += block[j];
					}
					else
					{
						int num = j * 316; // 第j号块的第一个数
						while (tmp + hashTable[num] < median)
						{
							tmp += hashTable[num++];
						}
						printf("%d\n", num);
						break;
					}
				}
			}
		}
		else if (!strcmp(op, "Pop")) {
			if (cnt == 0) {
				printf("Invalid\n");
			}
			else {
				int top = st.top();
				st.pop();
				block[top / 316]--;
				hashTable[top]--;
				cnt--;
				printf("%d\n", top);
			}
		}
		else {
			cnt++;
			scanf("%d", &e);
			st.push(e);
			block[e / 316]++;
			hashTable[e]++;
		}
	}
	return 0;
}
*/

/*树状数组+二分*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>

#define lowbit(i) (i&(-i))
using namespace std;
const int maxn = 100010;
int c[maxn];
void update(int x, int v) {
	for (int i = x; i < maxn; i += lowbit(i))
	{
		c[i] += v;
	}
}

int getSum(int x) {
	int sum = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		sum += c[i];
	}
	return sum;
}

void peekMedian(int k) {
	int l = 1, r = maxn, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (getSum(mid) < k)
		{
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	printf("%d\n", r);
}

int main() {
	// 输入
	int n, cnt = 0, e;
	char op[12];
	stack<int> st;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", op);
		if (!strcmp(op, "PeekMedian")) {

			if (cnt == 0) {
				printf("Invalid\n");
			}
			else
			{
				// 这里因为下标从1开始所以(cnt + 1)/2就是中位数的下标
				peekMedian((cnt + 1) >> 1); 
			}
		}
		else if (!strcmp(op, "Pop")) {
			if (cnt == 0) {
				printf("Invalid\n");
			}
			else {
				int top = st.top();
				st.pop();
				cnt--;
				printf("%d\n", top);
				update(top, -1);
			}
		}
		else {
			cnt++;
			scanf("%d", &e);
			st.push(e);
			update(e, 1);
		}
	}
	return 0;
}