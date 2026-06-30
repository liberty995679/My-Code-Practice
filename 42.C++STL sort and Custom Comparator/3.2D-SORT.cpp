//给定二维空间中的n个点，请将所有点按升序排序。
//    (x1, y1) > (x2, y2) if and only if (x1 > x2) or (x1 == x2 and y1 < y2) 
//输入
//第一行包含一个整数t，表示测试用例的数量。对于每个测试用例，第一行包含一个整数n，表示点的数量。接下来的n行每行包含两个整数xi，yi，表示该点的坐标。
//输出
//对于每个测试用例，按照点的顺序输出排序结果。
#include <iostream>
#include <algorithm>
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


void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first != b.first) return a.first < b.first;
		return 	a.second > b.second;
	});
	for (auto &i:arr) {
		cout << i.first << ' ' << i.second << enl;
	}cout << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
    return 0;
}