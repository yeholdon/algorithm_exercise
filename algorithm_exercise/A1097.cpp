#include <cstdio>
#include <algorithm>
const int maxn = 100010;
using namespace std;

struct Node
{
	int next;
	int w, abs;
} linkedList[maxn];

bool hashTable[10010] = { false };

int main() {
	// 首地址和结点数，没有单独的头节点
	int head, n;
	scanf("%d %d", &head, &n);
	int addr, w, nxt;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &addr, &w, &nxt);
		linkedList[addr].w = w;
		linkedList[addr].next = nxt;
		linkedList[addr].abs = abs(w);

	}

	int cur_dup, cur = head, head_dup = -1;
	bool head_flag = false;
	for (int i = head; i != -1 ; i = linkedList[i].next)
	{
		if (hashTable[linkedList[i].abs] == false) {
			hashTable[linkedList[i].abs] = true;
			//linkedList[cur].next = -1; // 这个很重要，因为要重新构建链表所以要先清除原来的内容
			if (i != head) {
				linkedList[cur].next = i;
			}
			cur = i;

		}
		else { // 重复
			if (head_flag == false) {
				// 重复链头节点
				head_flag = true;
				head_dup = i;
			}
			else
			{
				linkedList[cur_dup].next = i;
				//linkedList[i].next = -1;// 这个要先重置
			}
			cur_dup = i;
		}
		
	}
	// 这个点很重要，末尾的
	linkedList[cur].next = linkedList[cur_dup].next = -1;
	// 输出
	for (int i = head; i != -1; i = linkedList[i].next) {
		printf("%05d %d ", i, linkedList[i].w);
		if (linkedList[i].next == -1) {
			printf("-1\n");
		}
		else
		{
			printf("%05d\n", linkedList[i].next);
		}
		

	}
	for (int i = head_dup; i != -1; i = linkedList[i].next)
	{
		printf("%05d %d ", i, linkedList[i].w);
		if (linkedList[i].next == -1) {
			printf("-1\n");
		}
		else
		{
			printf("%05d\n", linkedList[i].next);
		}
	}
}