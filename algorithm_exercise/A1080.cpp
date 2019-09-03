#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 40010;
const int maxm = 110;
struct Student
{
	int sum, grade;
	int rank, index;
	vector<int> choices;
}stus[maxn];

bool cmp(Student& a, Student& b) {
	if (a.sum != b.sum)
	{
		return a.sum > b.sum;
	}
	else {
		return a.grade > b.grade;
	}
}

int quotas[maxm] = { 0 };
vector<int> admissions[maxm];
int main() {
	//  ‰»Î
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &quotas[i]);
	}
	int wGrade, iGrade;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &wGrade, &iGrade);
		stus[i].index = i;
		stus[i].grade = wGrade;
		stus[i].sum = wGrade + iGrade;
		for (int j = 0; j < k; j++)
		{
			int chioce;
			scanf("%d", &chioce);
			stus[i].choices.push_back(chioce);
		}
	}

	// ≈≈–Ú
	sort(stus, stus + n, cmp);
	stus[0].rank = 1;
	for (int i = 0; i < n; i++)
	{
		if (i != 0) {
			if (stus[i].sum == stus[i - 1].sum && stus[i].grade == stus[i - 1].grade) {
				stus[i].rank = stus[i - 1].rank;
			}
			else
			{
				stus[i].rank = stus[i - 1].rank + 1; 
			}
		}
	}
	int i = 0;
	bool hashTable[maxm] = { false };
	while (i < n)
	{
		for (int j = 0; j < stus[i].choices.size(); j++)
		{
			int choice = stus[i].choices[j];
			if (quotas[choice] > 0) {
				quotas[choice]--;
				hashTable[choice] = true;
				admissions[choice].push_back(stus[i].index);
				break;
			}
		}
		i++;
		while (i != 0 && i < n && stus[i].rank == stus[i - 1].rank )
		{
			for (int j = 0; j < stus[i].choices.size(); j++)
			{
				int choice = stus[i].choices[j];
				if (quotas[choice] > 0) {
					quotas[choice]--;
					hashTable[choice] = true;
					admissions[choice].push_back(stus[i].index);
					break;
				}
				else {
					if (hashTable[choice] == true) {
						admissions[choice].push_back(stus[i].index);
						break;
					}
				}
			}
			i++;
		}
		memset(hashTable, false, sizeof(hashTable));
	}

	for (int i = 0; i < m; i++)
	{
		sort(admissions[i].begin(), admissions[i].end());
		for (int j = 0; j < admissions[i].size(); j++)
		{
			if (j != 0) printf(" ");
			printf("%d", admissions[i][j]);
		}
		printf("\n");
	}

	return 0;
}