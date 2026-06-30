//你被给定了餐厅中 n 位顾客的到达时间和离开时间。
//问：在任意时刻，餐厅内顾客的最大数量是多少？
//输入​
//第一行有一个整数 n：表示顾客的数量。
//接下来 n 行，每行描述一位顾客，包含两个整数 a 和 b：分别表示该顾客的到达时间和离开时间。
//你可以假设所有到达时间和离开时间都是不同的。
//输出​
//输出一个整数：表示餐厅内同时存在的最大顾客数量
#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;
using vi = vector<int>;
const char enl = '\n';

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({a, 1});
		arr.push_back({b, -1});
	}
	sort(arr.begin(), arr.end());
	int cur = 0;
	for (auto it: arr) {
		cur += it.second;
		mx = max(cur, mx);
	}
	cout << mx << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}