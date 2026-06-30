//你被给定一个由 n个非负整数组成的数组 a。然而，a中的一些元素缺失了，用 −1表示。
//我们定义数组 a是“好”的，当且仅当对于每个 1≤i≤n−2，都满足：
//mex( [a_i, a{i+1}, a{i+2}] ) = max( [a_i, a{i+1}, a{i+2}] ) - min( [a_i, a{i+1}, a{i+2}] )
//其中 mex(b) 表示集合 b 中未出现的最小非负整数。
//你需要判断能否通过将每个 -1 替换为一个非负整数，使得数组 a 变成“好”数组。
//输入
//每个测试包含多个测试用例。第一行包含测试用例的数量 t（1 ≤ t ≤ 500）。每个测试用例的描述如下：
//第一行包含一个整数 n（3 ≤ n ≤ 100）——数组的长度。
//第二行包含 n 个整数 a_1, a_2, …, a_n（-1 ≤ a_i ≤ 100）——数组的元素。a_i = -1 表示该元素缺失。
//输出
//对于每个测试用例，如果可以使数组变成“好”的，输出 "YES"，否则输出 "NO"。
//你可以以任意大小写输出答案。例如，字符串 "yEs"、"yes"、"Yes" 和 "YES" 都将被视为肯定回答。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	unordered_map<int, int> mp;
	int mx = 0;
	int mn = INT_MAX;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			cnt++;
			continue;
		}
		mx = max(a[i], mx);
		mn = min(a[i], mn);
		mp[a[i]]++;
	}
	int mex = mx - mn;
	if (mex < 0) mex = n;
	queue<int> b;
	for (int i = 0; i < mex; i++) {
		if (!mp.count(i)) {
			b.push(i);		
		}
	}
	if (cnt != 0) {
		if (b.size() > cnt || mp.count(mex)) {
			cout << "NO" << enl;
			return;
		}
		cout << "YES" << enl;
	} else {
		if (mp.count(mex)) {
			cout << "NO" << enl;
			return;
		}
		for (int i = 0; i < mex; i++) {
			if (!mp.count(i)) {
				cout << "NO" << enl;
				return;
			}
		}
		cout << "YES" << enl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}