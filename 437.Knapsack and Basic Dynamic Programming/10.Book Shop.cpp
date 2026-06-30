//你在一家书店里，这家店有 n 本不同的书。你知道每本书的价格和页数。
//你决定本次购书的总花费最多为 x。
//请问：在满足预算的前提下，你最多能买到多少页的书？
//每本书最多只能买一次。
//输入
//第一行输入两个整数 n 和 x：书的本数和最大总预算。
//第二行输入 n 个整数 h₁, h₂, …, hₙ：表示每本书的价格。
//第三行输入 n 个整数 s₁, s₂, …, sₙ：表示每本书的页数。
//输出
//输出一个整数：在不超过预算 x 的前提下，所能获得的最大页数总和。
//约束条件
//1 ≤ n ≤ 1000
//1 ≤ x ≤ 10⁵
//1 ≤ hᵢ, sᵢ ≤ 1000
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
const ll INF = LLONG_MAX;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> h(n), s(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> s[i];
	vector<vector<int>> dp(n + 1, vector<int>(x + 1));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= h[i - 1]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
			}
		}
	}
	cout << dp[n][x];
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