#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 110;
using namespace std;

int a[maxn];
int b[maxn];
int nxt[maxn];

bool insertionSort(int n) {
	bool flag = false;
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

void merge(int A[], int L1, int R1, int L2, int R2) {
	int i = L1, j = L2, k = 0;
	int tmp[maxn];
	while (i <= R1 && j <= R2)
	{
		if (A[i] < A[j]) {
			tmp[k++] = A[i++];
		}
		else {
			tmp[k++] = A[j++];
		}
	}

	while (i <= R1) tmp[k++] = A[i++];
	while (j <= R2) tmp[k++] = A[j++];
	for (int p = 0; p < k; p++)
	{
		A[L1 + p] = tmp[p];
	}
}

bool flag = false;
void mergeSortRecursion(int A[], int left, int right, int n) {
	
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSortRecursion(A, left, mid, n);
		mergeSortRecursion(A, mid + 1, right, n);
		merge(A, left, mid, mid + 1, right);
		if (flag) {
			// 记录下一轮的结果
			for (int i = 0; i < n; i++)
			{
				nxt[i] = A[i];
			}
			return;
		}
		// 比较这轮递归结果
		flag = true;
		for (int i = 0; i < n; i++)
		{
			if (A[i] != b[i]) {
				flag = false;
				break;
			}
		}

	}
}

void mergeSort(int A[], int n) {
	bool flag = false;
	for (int step = 2; step/2 < n; step*=2)
	{
		for (int i = 0; i < n; i+=step)
		{
			int mid = i + step / 2 - 1;
			merge(A, i, mid, mid + 1, min(i + step - 1 , n - 1));
		}
		if (flag) {
			// 记录下一轮的结果
			for (int i = 0; i < n; i++)
			{
				nxt[i] = A[i];
			}
			return;
		}
		flag = true;
		for (int i = 0; i < n; i++)
		{
			if (A[i] != b[i]) {
				flag = false;
				break;
			}
		}
	}
}

int main() {
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

	if (insertionSort(n) == true) {
		printf("Insertion Sort\n");
		for (int i = 0; i < n; i++)
		{
			if (i != 0) {
				printf(" ");

			}
			printf("%d", nxt[i]);
		}
	}
	else
	{
		mergeSort(a, n);
		printf("Merge Sort\n");
		for (int i = 0; i < n; i++)
		{
			if (i != 0) {
				printf(" ");

			}
			printf("%d", nxt[i]);
		}
	}
	return 0;
}