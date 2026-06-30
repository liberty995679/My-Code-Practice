// 你的任务是统计在区间 a到 b之间（包含端点）的整数中，没有任意两个相邻数字相同的整数个数。
// 输入​
// 输入仅一行，包含两个整数 a和 b。
// 输出​
// 输出一个整数：问题的答案。
// 数据范围​
// 0≤a≤b≤10^18
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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

ll dp[20][11][2];
string s;
ll dfs(int pos, int pre, bool tight) {
	if (pos == (int)s.size()) return 1;
	if (dp[pos][pre + 1][tight] != -1) return dp[pos][pre + 1][tight]; //"负一映射到零"：任何可能为负的状态，都加一个偏移量让它变成非负。
	ll ans = 0;
	int up = tight ? s[pos] - '0' : 9;
	for (int d = 0; d <= up; d++) {
		if (pre == -1) {  // 还没开始选数字（前导零阶段）
			if (d == 0) ans += dfs(pos + 1, -1, tight && d == up);
			else ans += dfs(pos + 1, d, tight && d == up);
		} else {  // 已经开始选数字了
			if (d != pre) ans += dfs(pos + 1, d, tight && d == up);
		}
	}
	return dp[pos][pre + 1][tight] = ans;
}

ll check(ll n) {
	s = to_string(n);
	memset(dp, -1, sizeof(dp));
	return dfs(0, -1, 1);
}

void solve() {
	ll a, b;
	cin >> a >> b;
	cout << check(b) - check(a - 1) << enl;
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