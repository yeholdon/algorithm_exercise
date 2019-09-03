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
	// �׵�ַ�ͽ������û�е�����ͷ�ڵ�
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
			//linkedList[cur].next = -1; // �������Ҫ����ΪҪ���¹�����������Ҫ�����ԭ��������
			if (i != head) {
				linkedList[cur].next = i;
			}
			cur = i;

		}
		else { // �ظ�
			if (head_flag == false) {
				// �ظ���ͷ�ڵ�
				head_flag = true;
				head_dup = i;
			}
			else
			{
				linkedList[cur_dup].next = i;
				//linkedList[i].next = -1;// ���Ҫ������
			}
			cur_dup = i;
		}
		
	}
	// ��������Ҫ��ĩβ��
	linkedList[cur].next = linkedList[cur_dup].next = -1;
	// ���
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