// 史蒂夫和另外 n 个村民住在一个村子里。不幸的是，由于绿宝石分配上的争端，那些村民彼此之间都不是朋友。此外，村民 i 最初有 gi 的暴躁值。
// 史蒂夫可以执行以下操作任意次数：
// 选择两个村民 i 和 j，给他们 max(gi, gj) 颗绿宝石让他们平分（共享）。他们两人的暴躁值都减少 min(gi, gj)，并且如果他们之前不是朋友，现在会成为朋友。
// 史蒂夫希望让每个村民都与其他所有村民成为朋友（可能通过某些中间友谊）；也就是说，从任何一个村民出发，你都可以通过一条友谊路径到达任何其他村民。由于他不想过度膨胀村庄经济，请计算他要实现这一目标必须送出的最少绿宝石数量。
// 输入
// 每个测试包含多个测试用例。第一行包含测试用例的数量 t (1≤t≤10^4)。接下来是对测试用例的描述。
// 每个测试用例的第一行包含一个整数 n (2≤n≤2⋅10^5) —— 村民的数量。
// 每个测试用例的第二行包含 n 个整数 g1, g2, …, gn (1≤gi≤10^9) —— 每个村民的初始暴躁值。
// 保证所有测试用例中 n 的总和不超过 2⋅10^5。
// 输出
// 对于每个测试用例，输出一个整数 —— 史蒂夫必须送出以使所有人成为朋友的最少绿宝石数量。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
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
string s = " ";

void solve() {
	int n;
	cin >> n;
	vector<ll> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ll ans = 0;
	sort(arr.begin(), arr.end());
	if (n % 2 == 0) {
		for (int i = 1; i <= n; ++i) {
			if (i % 2 == 0) ans += arr[i];
		}
	} else {
		for (int i = 1; i <=n; i++) {
			if (i & 1) ans += arr[i];
		}
	}
	cout << ans << enl;
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