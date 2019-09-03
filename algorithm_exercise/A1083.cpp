#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 110;
struct Record
{
	char name[12];
	char ID[12];
	int grade;
} records[maxn];
bool cmp(Record& a, Record& b) {
	return a.grade > b.grade;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s %d", &records[i].name, &records[i].ID, &records[i].grade);

	}
	int grades1, grades2;
	scanf("%d%d", &grades1, &grades2);

	// ÅÅÐò
	sort(records, records + n, cmp);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (records[i].grade <= grades2) {
			if (records[i].grade >= grades1) {
				cnt++;
				printf("%s %s\n", records[i].name, records[i].ID);
			}
			else
			{
				break;
			}
		}
		
	}
	if (cnt == 0) printf("NONE\n");
	return 0;
}