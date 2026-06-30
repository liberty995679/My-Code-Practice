// 求在 1到 K（包含两端）之间的整数中，满足以下条件的整数个数，并对 109+7取模：
// 其十进制表示的各位数字之和是 D的倍数。
// 数据范围
// 输入中的所有值均为整数。
// 1≤K<10 ^10000
// 1≤D≤100
// 输出
// 输出满足条件的整数个数，对 10^9+7取模后的结果。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <cstring>
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
const int mod = 1e9 + 7;

int d;
vector<vector<vector<ll>>> dp;
string s;

ll dfs(int pos, int state, int limit) {
	if (pos == (int)s.size()) {
		return (state % d == 0) ? 1 : 0;
	}
	if (dp[pos][state][limit] != -1) {
		return dp[pos][state][limit];
	}
	ll ans = 0;
	int up = limit ? (s[pos] - '0') : 9;
	for (int i = 0; i <= up; i++) {
		ans = (ans + dfs(pos + 1, (state + i) % d,  limit && i == up)) % mod;
	}
	return dp[pos][state][limit] = ans;
}

ll check(string k) {
	s = k;
	dp.assign(s.size(), vector<vector<ll>>(d, vector<ll>(2, -1)));
	return (dfs(0, 0, 1) - 1 + mod) % mod;
}

void solve(){
	string k;
	cin >> k >> d;
	cout << check(k) << enl;
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