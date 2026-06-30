//考虑一个由 n 枚硬币组成的货币系统。每枚硬币都有一个正整数面值。
//你的任务是使用可用的硬币凑出金额 x，并且要求使用的硬币数量最少。
//例如，如果硬币面值为 {1, 5, 7}，目标金额为 11，那么最优解是 5+5+1，这需要 3 枚硬币。
//输入
//第一行包含两个整数 n 和 x：硬币的数量和目标金额。
//第二行包含 n 个不同的整数 c₁, c₂, ..., cₙ：每枚硬币的面值。
//输出
//输出一个整数：所需的最少硬币数量。如果无法凑出目标金额，输出 -1。
//约束条件
//1 ≤ n ≤ 100
//1 ≤ x ≤ 10⁶
//1 ≤ cᵢ ≤ 10⁶
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
const int mod = 1e9 + 7;
void solve() {
	int n, x;
	cin >> n >> x;
	vector<ll> v(n); //不能包含无用的v0
	vector<ll> dp(x + 1, LLONG_MAX); //将 dp 数组初始化为 INT_MAX，这样就不需要特殊处理 dp[2]
	for (int i = 0; i < n; i++) cin >> v[i];
	dp[0] = 0;
	for (ll i = 1; i <= x; i++) {
		for (ll val: v) {
			if (i >= val && dp[i - val] != LLONG_MAX) //保证不出现负数金额 保证这个子问题是能凑出来的
				dp[i] = min(dp[i], dp[i - val] + 1);
		}
	}
	if (dp[x] == LLONG_MAX) cout << -1 << enl;
	else cout << dp[x] << enl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
    return 0;
}