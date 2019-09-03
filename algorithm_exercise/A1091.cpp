#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int x, y, z;
	Node(int x_, int y_, int z_) {
		x = x_;
		y = y_;
		z = z_;
	}
};

const int maxn = 128;
const int maxm = 1286;
const int maxl = 60;


int graph[maxl][maxm][maxn] = { -1 };
bool vis[maxl][maxm][maxn] = { false };
int num = 0;
int m, n, l, t;

// ��DFSӦ���ǵݹ����ռ临�Ӷ�̫�󣬻ᱬջ�����ز���û������
void DFS(int i, int j, int k, int &cnt) {
	vis[i][j][k] = true;
	cnt++;
	int X[6] = {1, -1, 0, 0, 0, 0};
	int Y[6] = {0, 0, 1, -1, 0, 0};
	int Z[6] = {0, 0, 0, 0, 1, -1};
	for (int p = 0; p < 6; p++)
	{
		int z = i + X[p];
		int x = j + Y[p];
		int y = k + Z[p];
		if ((z >= 0 && z < l) && (x >= 0 && x < m) && (y >= 0 && y < n)) {
			if (vis[z][x][y] == false && graph[z][x][y] == 1) {
				DFS(z, x, y, cnt);
			}
		}

	}
}

int BFS(int i, int j, int k) {
	// ��ΪBFSû�еݹ飬�����÷���ֵ����
	int cnt = 0; //��¼��Ĵ�С
	queue<Node> q;
	q.push(Node(j, k, i));
	vis[i][j][k] = true;
	while (!q.empty())
	{
		Node top = q.front();
		q.pop();
		// ��������Ϣ����ʱ�ٽ���
		cnt++;
		int X[6] = { 1, -1, 0, 0, 0, 0 };
		int Y[6] = { 0, 0, 1, -1, 0, 0 };
		int Z[6] = { 0, 0, 0, 0, 1, -1 };
		for (int p = 0; p < 6; p++)
		{
			int z = top.z + Z[p];
			int x = top.x + X[p];
			int y = top.y + Y[p];
			if ((z >= 0 && z < l) && (x >= 0 && x < m) && (y >= 0 && y < n)) {
				if (vis[z][x][y] == false && graph[z][x][y] == 1) {
					q.push(Node(x, y, z));
					vis[z][x][y] = true;
				}
			}

		}
	}

	if (cnt >= t) {
		return cnt;
	}
	else return 0;
}

int main() {
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				scanf("%d", &graph[i][j][k]);
			}
		}
	}

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (vis[i][j][k] == false && graph[i][j][k] == 1) {
					num += BFS(i, j, k);
				}
			}
		}
	}

	printf("%d\n", num);
	
	return 0;
}