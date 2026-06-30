// 给定一个长度为 n的数组 a。
// 对于每个下标 i（满足 1 ≤ i < n），你最多可以对它执行一次如下操作：
// 令 a[i] := a[i] XOR a[i+1]
// （其中 XOR表示按位异或运算）
// 你可以按任意顺序选择下标并执行这些操作。
// 现在给定另一个长度为 n的数组 b，判断是否能将数组 a通过上述操作变换为数组 b。
// 输入
// 每个测试包含多组测试用例。
// 第一行包含一个整数 t（1 ≤ t ≤ 10^4），表示测试用例的数量。
// 每个测试用例的第一行包含一个整数 n（2 ≤ n ≤ 2·10^5）。
// 第二行包含 n个整数 a1, a2, …, an（0 ≤ ai < 2^30）。
// 第三行包含 n个整数 b1, b2, …, bn（0 ≤ bi < 2^30）。
//保证所有测试用例中 n的总和不超过 2·10^5。
//输出
//对于每个测试用例，如果可以将 a变换为 b，输出 "YES"；否则输出 "NO"。
//不区分大小写（例如 "yEs", "yes"均可视为肯定答案）。
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
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	if (a[n - 1] != b[n - 1]) {
		cout << "NO" << enl;
		return;
	}
	for (int i = n - 2; i >= 0; i--) {
		ll x = a[i] ^ a[i + 1];
		if (b[i] == a[i]) continue;
		if (b[i] == x || b[i] == (a[i] ^ b[i + 1])) {
			continue;
		} else {
			cout << "NO" << enl;
			return;
		}
	}
	cout << "YES" << enl;
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