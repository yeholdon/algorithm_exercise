#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 100010;

int n, root;
double P, r;
int MAXN = 1, maxL = 0;
struct Node
{
	int layer;
	int price;
	vector<int> childs;

}nodes[maxn];

double getPrice(int layer_) {
	double max_price = P * pow((1.0 + r/100), layer_ - 1);
	return max_price;
}

void BFS(int i) {
	queue<Node> q;
	nodes[root].layer = 1;
	q.push(nodes[root]);
	while (!q.empty())
	{
		Node top = q.front();
		if (maxL == top.layer) {
			MAXN++;
		}
		else if (maxL < top.layer) {
			maxL = top.layer;
			MAXN = 1;
		}
		q.pop();
		for (int i = 0; i < top.childs.size(); i++)
		{
			nodes[top.childs[i]].layer = top.layer + 1;
			q.push(nodes[top.childs[i]]);
		}

	}
}
int main() {

	scanf("%d%lf%lf", &n, &P, &r);
	for (int i = 0; i < n; i++)
	{
		int fa;
		scanf("%d", &fa);
		if (fa == -1) {
			root = i;
		}
		else {
			nodes[fa].childs.push_back(i);
		}
	}

	BFS(root);
	double max_price = getPrice(maxL);
	printf("%.2f %d\n", max_price, MAXN);

	return 0;
}