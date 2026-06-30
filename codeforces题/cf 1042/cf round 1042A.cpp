//在分流宇宙中，杠杆会进行迭代，给定两个长度为 n 的数组 a 和 b。在每次迭代中，杠杆会执行以下操作：
//随机选择一个索引 i，使得 a[i] > b[i]。然后将 a[i] 减少 1。如果不存在这样的索引 i，则忽略此步骤。
//随机选择一个索引 i，使得 a[i] < b[i]。然后将 a[i] 增加 1。如果不存在这样的索引 i，则忽略此步骤。
//每次迭代后，杠杆会检查步骤 1 是否被忽略，如果是，则结束迭代。
//给你两个数组。找出杠杆进行的迭代次数。可以证明，无论杠杆在每一步选择哪个随机索引，这个次数都是固定的。
//输入格式
//每个测试包含多个测试用例。第一行包含测试用例的数量 t（1 ≤ t ≤ 10^4）。接下来是测试用例的描述。
//每个测试用例的第一行包含一个整数 n（1 ≤ n ≤ 10）。
//每个测试用例的第二行包含 n 个整数 a[1], a[2], …, a[n]（1 ≤ a[i] ≤ 10）。
//每个测试用例的第三行包含 n 个整数 b[1], b[2], …, b[n]（1 ≤ b[i] ≤ 10）。
//输出格式
//对于每个测试用例，输出一个整数——杠杆进行的迭代次数。
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
 	ll n;
 	cin >> n;
 	vector<ll> a(n), b(n);
 	for (int i = 0; i < n;i++) cin >> a[i];
 	for (int i = 0; i < n;i++) cin >> b[i];
 	ll ans = 0;
 	for (int i = 0; i < n; i++) {
 		if (a[i] > b[i]) {
 			ans += a[i] - b[i];
		}
	}
	cout << ans + 1 << enl;
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