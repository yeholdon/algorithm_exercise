#include <cstdio> 
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
const int maxn = 110;

using namespace std;

struct Node
{
	int layer;
	vector<int> childs;
	Node() {
		layer = 0;
		childs.clear();
	};
	Node(int layer_, vector<int> child_) {
		layer = layer_;
		childs = child_;
	}
}pedigree[maxn];

int hashCnt[maxn] = { 0 };

int main() {
	// 建树
	int n, m;
	scanf("%d%d", &n, &m);
	int addr, k;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &addr, &k);
		for (int j = 0; j < k; j++)
		{
			int c;
			scanf("%d", &c);
			pedigree[addr].childs.push_back(c);
		}
	}

	// 层序遍历，并设置layer
	queue<Node> q;
	pedigree[1].layer = 1; // 根的层号为1
	q.push(pedigree[1]); // 根结点入队
	int maxL = 0;
	while (!q.empty())
	{
		Node top = q.front();
		hashCnt[top.layer]++;
		maxL = max(maxL, top.layer);
		q.pop();
		for (int i = 0; i < top.childs.size(); i++)
		{
			int child = top.childs[i];
			pedigree[child].layer = top.layer + 1;
			q.push(pedigree[child]); // 子结点全部入队
		}
	}
	int maxgn = -1, index = 0;
	for (int i = 1; i <= maxL; i++)
	{
		if (maxgn < hashCnt[i]) {
			maxgn = hashCnt[i];
			index = i;
		}
	}

	printf("%d %d\n", maxgn, index);
	return 0;
}