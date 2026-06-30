//在一个列表中有许多人的姓名和出生年份。你的任务是按年龄从小到大打印姓名。（没有两个人有相同的年龄。）
//输入
//第一行包含一个整数 T≤100，表示测试用例的数量。
//对于每个测试用例，有一个正整数 n(1≤n≤100)
//表示人数，接下来有 n行，每行包含一个姓名和一个出生年份（1900-2015），用一个空格分隔。
//姓名的长度为正整数且不超过 100
//。注意姓名只包含字母、数字和空格。
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
#include <bitset>
using namespace std;
using ll = long long;
const char enl = '\n';

bool check(string s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	cin.ignore();
	vector<pair<string, int>> arr(n);
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		string a, name;
		int day;
		stringstream ssin(s);
		while (ssin >> a) {
			if (!check(a)) {
				if (!name.empty()) name += " "; 
				name += a;
			} else {
				day = stoi(a);
			}
		}
		arr[i] = {name, day};
	}
	sort(arr.begin(), arr.end(), [](const pair<string, int>& a, const pair<string, int>& b){
		return a.second > b.second;
	});
	for (auto& i: arr) {
		cout << i.first << enl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) solve();
    return 0;
}