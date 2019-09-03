/*
1. ����BST��дcreateBST(Node *root)����������insert
	
2. ���������BFS

���ԣ����ṹӦ����Ŀ�Ѹ�����Ӧ�����������ͬʱ����С�������Ȩֵ���ٲ���������
*/
#include <cstdio> 
#include <algorithm>
#include <queue>
const int maxn = 110;
using namespace std;

// BST���ṹ
struct Node
{
	int lchild, rchild;
	int w;
};

Node nodes[maxn];

int ptr = 0;
int newNode(int w) {
	nodes[ptr].w = w;
	nodes[ptr].lchild = nodes[ptr].rchild = -1;
	return ptr++;
}

void insert(int &p, int w) {
	// ��ǰ���Ϊ�գ�nodes[p].lchild == -1 && nodes[p].rchild == -1
	if (p == -1) {
		p = newNode(w);
		return;
	}
	
	if (nodes[p].w > w) {
		insert(nodes[p].lchild, w);
	}
	else {
		insert(nodes[p].rchild, w);
	}
	return;
}

int createBST(int data[], int n) {
	int root = -1; // �½�root��㣬�������insert����������
	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}
	return root;
}

int index = 0;
void inorder(int root, int data[]) {
	if (root == -1) {
		return;
	}
		
	inorder(nodes[root].lchild, data);
	nodes[root].w = data[index++];
	inorder(nodes[root].rchild, data);
}

void LayerOrder(int root) {
	queue<int> q;
	q.push(root);
	int cnt = 0;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		cnt++;
		if (cnt != 1) {
			printf(" ");
		}
		printf("%d", nodes[top].w);
		
		if (nodes[top].lchild != -1) q.push(nodes[top].lchild);
		if (nodes[top].rchild != -1) q.push(nodes[top].rchild);

	}
}

int main() {
	// ��ȡ���룬����
	int n;
	int data[maxn];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		nodes[i].lchild = l;
		nodes[i].rchild = r;
	}
	// ��ȡȨֵ���У�����
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	sort(data, data + n);

	// ����Ȩֵ
	inorder(0, data);

	// �������
	LayerOrder(0);
	return 0;
}