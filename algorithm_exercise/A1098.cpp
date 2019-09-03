#include <cstdio>
#include <algorithm>

const int maxn = 110;
using namespace std;

int a[maxn];
int b[maxn];
int nxt[maxn];

bool insertionSort(int n) {
	bool flag = false, flagNext = false;
	// 复制一份
	int ai[maxn];
	for (int i = 0; i < n; i++) {
		ai[i] = a[i];
	}

	for (int i = 1; i < n; i++) {
		int temp = ai[i];
		int j;
		for (j = i; j > 0; j--) {
			if (temp < ai[j - 1]) {
				ai[j] = ai[j - 1];
			}
			else {
				break;
			}
		}
		ai[j] = temp;
		// 保存下一轮序列后退出
		if (flag == true) {
			for (int k = 0; k < n; k++)
			{
				nxt[k] = ai[k];
				
			}
			return true;
		}
		//比较中间结果
		flag = true;
		for (int k = 0; k < n; k++)
		{
			if (ai[k] != b[k])
			{
				flag = false;
				break;
			}
		}
		
	}
	return false;
	
}

void downAdjust(int low, int high, int a[]) {
	int i = low, j = 2 * i;// high为数组最后一个结点，low为当前待调整非叶子结点
	while (j <= high)
	{
		if (j + 1 <= high && a[j] < a[j + 1]) {
			j++;
		}
		if (a[i] < a[j]) {
			swap(a[i], a[j]);
			i = j;
			j = 2 * i;
		}
		else
			break;
	}
	
}
bool heapSort(int n) {
	bool flag = false;
	// 复制一份
	int ah[maxn];
	for (int i = 0; i < n; i++) {
		ah[i + 1] = a[i];
	}
	// 建堆，大顶堆
	for (int i = n / 2; i > 0; i--) {
		downAdjust(i, n, ah);
	}
	// 堆排序
	for (int i = n; i > 1; i--)
	{
		swap(ah[i], ah[1]);
		downAdjust(1, i - 1, ah);
			
		if (flag == true) {
			for (int j = 0; j < n; j++) {
				nxt[j] = ah[j + 1];
			}
			return true;
		}
		flag = true;
		for (int j = 0; j < n; j++)
		{
			if (ah[j + 1] != b[j]) {
				flag = false;
				break;
			}
		}
	}


	return false;
}

int main() {
	// 获取输入
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}

	if (insertionSort(n)) {
		printf("Insertion Sort\n");

	}
	else
	{
		heapSort(n);
		printf("Heap Sort\n");
	}
	for (int i = 0; i < n; i++) {
		if (i > 0) printf(" ");
		printf("%d", nxt[i]);
	}
	return 0;
}