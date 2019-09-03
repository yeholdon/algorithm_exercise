/*
1. 构建BST，写createBST(Node *root)函数，不断insert
	
2. 层序遍历，BFS

不对，树结构应该题目已给出。应该中序遍历的同时，从小到大插入权值。再层序遍历输出
*/
#include <cstdio> 
#include <algorithm>
#include <queue>
const int maxn = 110;
using namespace std;

// BST结点结构
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
	// 当前结点为空，nodes[p].lchild == -1 && nodes[p].rchild == -1
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
	int root = -1; // 新建root结点，这里体会insert参数加引用
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
	// 获取输入，建树
	int n;
	int data[maxn];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		nodes[i].lchild = l;
		nodes[i].rchild = r;
	}
	// 获取权值序列，排序
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	sort(data, data + n);

	// 填入权值
	inorder(0, data);

	// 层序遍历
	LayerOrder(0);
	return 0;
}