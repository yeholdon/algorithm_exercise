#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int maxn = 210;
const int INF = 1 << 31 - 1;
int G[maxn][maxn] = { 0 }, cost, d[maxn] = { 0 }, w[maxn] = { 0 };
int num[maxn], maxW = 0;
vector<int> pre[maxn], path, temp_path;
string st, c1, c2, tmp;
int happiness[maxn];
int n, k;
double maxAve = -1.0;
map<string, int> mp;
map<int, string> mp1;

void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	fill(num, num + maxn, 0);
	bool vis[maxn] = { false };
	d[s] = 0;
	num[s] = 1;
	for (int i = 0; i < n; i++)
	{
		int MIN = INF, u = -1;
		for (int j = 0; j < n; j++)
		{
			if (vis[j] == false && d[j] < MIN) {
				MIN = d[j];
				u = j;
			}

		}
		if (u == -1) return; // 剩余结点不连通
		vis[u] = true;
		// 更新可达d[i]；
		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + happiness[v];
					num[v] = num[u];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (d[u] + G[u][v] == d[v]) {
					if (w[v] < w[u] + happiness[v]) {
						w[v] = w[u] + happiness[v];
					}
					num[v] += num[u];
					pre[v].push_back(u);
				}

			}
		}

	}


}

void DFS(int v, int st) {
	if (v == st) {
		temp_path.push_back(v);
		// 计算权值和以及平均值
		int tempW = 0;
		for (int i = temp_path.size() - 2; i >= 0; i--)
		{
			tempW += happiness[temp_path[i]];
		}
		double t = 1.0 * tempW / (temp_path.size() - 1);
		if (tempW > maxW) {
			maxW = tempW;
			maxAve = t;
			path = temp_path;
		}
		else if (tempW == maxW && t > maxAve) {
			maxAve = t;
			path = temp_path;
		}
		temp_path.pop_back();
		return;
	}

	temp_path.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i], st);
	}

	temp_path.pop_back();
}
int main() {
	fill(G[0], G[0] + maxn * maxn, INF);
	fill(happiness, happiness + maxn, 0);
	// scanf("%d%d%s", &n, &k, start);
	cin >> n >> k >> st;
	mp[st] = 0;
	mp1[0] = st;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> tmp >> happiness[i + 1];
		mp[tmp] = i + 1;
		mp1[i + 1] = tmp;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> c1 >> c2 >> cost;
		G[mp[c1]][mp[c2]] = cost;
		G[mp[c2]][mp[c1]] = cost;
	}

	Dijkstra(0);
	DFS(mp["ROM"], 0);
	cout << num[mp["ROM"]] << ' ' << d[mp["ROM"]] << ' ' << w[mp["ROM"]] << ' ' << (int)maxAve << endl;
	for (int i = path.size() - 1; i >= 0; i--)
	{

		cout << mp1[path[i]];
		if (i != 0) cout << "->";
	}
}