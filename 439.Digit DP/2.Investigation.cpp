// 一个整数如果它的各位数字之和能被3整除，那么这个整数本身也能被3整除。
// 举个例子，3702能被3整除，因为3+7+0+2=12，也能被3整除。这个规律对数字9同样适用。
// 这道题，我们要来探索一下其他整数是否也有类似的“数字和整除”特性。
// 输入
// 输入第一行是一个整数 T（≤ 200），表示测试用例的数量。
// 接下来每个测试用例包含三个正整数 A, B 和 K（1 ≤ A ≤ B < 2^31，0 < K < 10000）。
// 输出
// 对于每个测试用例，输出“案例编号”和区间 [A, B] 中满足以下条件的整数个数：该整数能被 K 整除，且它的各位数字之和也能被 K 整除。
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

ll dp[20][100][100][2]; //数位左边，数位和，原数和，限制
string s;
int k;
ll dfs(int pos, int state, ll num, int limit) {
	if (pos == s.size()) {
    	return (state % k == 0 && num % k == 0) ? 1 : 0;
	}
	if (dp[pos][state][num][limit] != -1) {
		return dp[pos][state][num][limit];
	}
	int up = limit ? s[pos] - '0': 9;
	ll ans = 0;
	for (int d = 0; d <= up; d++) {
		ans += dfs(pos + 1, (state + d) % k, (num * 10 + d) % k, limit && d == up);
	}
	return dp[pos][state][num][limit] = ans;
}

ll check(ll n) {
	s = to_string(n);
	memset(dp, -1, sizeof(dp));
	return dfs(0, 0, 0, 1);
}

void solve() {
	ll a, b;
	cin >> a >> b >> k;
	if (k > 90) {  //数位和最大 = 9 * 10 =  90 如果 k > 90 → 数位和不可能 % k == 0
		cout << 0 << endl;
		return;
	}
	cout << check(b) - check(a - 1) << enl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}