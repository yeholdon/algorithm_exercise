#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Record
{
	string plate;
	string time;
	int ss;
	bool status;
	Record(string plate_, string time_, string status_) {
		plate = plate_;
		time = time_;
		if (status_ == "in") {
			status = true;
		}
		else if (status_ == "out")
		{
			status = false;
		}
		trans();
	}
	void trans() {
		int h = stoi(time.substr(0, 2));
		int m = stoi(time.substr(3, 2));
		int s = stoi(time.substr(6, 2));
		ss = h * 3600 + m * 60 + s;
	}
};

int trans(string time) {
	int h = stoi(time.substr(0, 2));
	int m = stoi(time.substr(3, 2));
	int s = stoi(time.substr(6, 2));
	return h * 3600 + m * 60 + s;
}

bool cmp(Record& a, Record& b) {
	if (a.plate != b.plate) return a.plate < b.plate;
	else {
		return a.ss < b.ss;
	}
}

bool cmp_on_time(Record& a, Record& b) {
	return a.ss < b.ss;
}
map<string, int> mp;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	string plate, time, status;
	vector<Record> v, vec_valid;
	for (int i = 0; i < n; i++)
	{
		cin >> plate >> time >> status;
		v.push_back(Record(plate, time, status));
		
	}
	// 获取合法的记录
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i].status == true && v[i + 1].status == false && v[i].plate == v[i+1].plate) {
			vec_valid.push_back(v[i]);
			vec_valid.push_back(v[i + 1]);
		}
	}

	vector<Record> vec = vec_valid; // 复制一份；
	// 将所有合法记录按照时间排序
	sort(vec_valid.begin(), vec_valid.end(), cmp_on_time);
	string t;
	int car_num = 0, now = 0;
	for (int j = 0; j < k; j++)
	{
		cin >> t;
		int s = trans(t);
		
		while(now < vec_valid.size())
		{
			if (s >= vec_valid[now].ss) {

				if (vec_valid[now].status == true) {
					car_num++;
				}
				else
				{
					car_num--;
				}
			}
			else
			{
				break;
			}
			now++;
		}
		cout << car_num << endl;


	}
	int maxT = 0;
	for (int i = 0; i < vec.size() - 1; i += 2)
	{
		mp[vec[i].plate] += vec[i + 1].ss - vec[i].ss;
		maxT = max(maxT, mp[vec[i].plate]);
	}

	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second == maxT) {
			cout << it->first << ' ';
		}
	}

	int ts = maxT;
	printf("%02d:%02d:%02d\n", ts / 3600, ts % 3600 / 60, ts % 60);


	return 0;
}