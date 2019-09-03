#include <cstdio> 
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 35;
int n = 0;
vector<int> pre, in, post;
stack<int> st;

struct Node
{
	Node* lchild, *rchild;
	int w;
};

Node* create(int preL, int preR, int inL, int inR) {
	if (preR < preL) {
		return NULL;
	}

	Node* root = new Node;
	root->w = pre[preL];
	// �������������ҵ�������±�
	int k = 0;
	for (int i = inL; i <= inR; i++)
	{
		if (in[i] == pre[preL]) {
			k = i;
			break;
		}
	}
	int Lnum = k - inL, Rnum = inR - k;

	root->lchild = create(preL + 1, preL + Lnum, inL, k - 1);
	root->rchild = create(preL + Lnum + 1, preR, k + 1, inR);
	return root;
}

void postOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	post.push_back(root->w);
}

int main() {
	// ���벢��ȡ�������������
	
	scanf("%d", &n);
	string str;
	int index;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> str;
		if (str == "Push") {
			cin >> index;
			pre.push_back(index);
			st.push(index);
		}
		else
		{
			int top = st.top();
			st.pop();
			in.push_back(top);
		}
	}

	// ��������ؽ�������
	Node* root = create(0, n - 1, 0, n - 1);
	postOrder(root);
	// �����������
	for (int i = 0; i < n; i++)
	{
		if (i != 0) {
			printf(" ");
		}
		printf("%d", post[i]);
	}

	return 0;
}