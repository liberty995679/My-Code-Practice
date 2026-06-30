//有 N 块石头，编号为 1, 2, …, N。对于每块石头 i（1 ≤ i ≤ N），其高度为 h_i。
//有一只青蛙最初位于石头 1 上。为了到达石头 N，它会重复以下动作若干次：
//如果青蛙当前在石头 i 上，它可以跳到石头 i+1、i+2、…、i+K 中的任意一块。此时会产生一个代价，大小为 |h_i − h_j|，其中 j 是它跳到的目标石头。
//求青蛙在到达石头 N 之前所产生的最小可能总代价。
//约束条件
//输入中的所有值均为整数。
//2 ≤ N ≤ 10^5
//1 ≤ K ≤ 100
//1 ≤ h_i ≤ 10^4
//输入
//输入来自标准输入，格式如下：
//N K
//h_1 h_2 … h_N
//输出
//输出最小可能的总代价。
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
	int n, k;
	cin >> n >> k;
	vector<ll> h(n + 1); 
	vector<ll> dp(n + 1, INT_MAX); //将 dp 数组初始化为 INT_MAX，这样就不需要特殊处理 dp[2]
	for (int i = 1; i <= n; i++) cin >> h[i];
	dp[1] = 0; 
	for (int i = 2; i <= n; i++) {
		for (int j = 1;i - j >= 1 && j <= k && j <= n; j++) { //来源石头的编号必须 ≥ 1（因为最小是石头1）
			dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
		}
	}
	cout << dp[n] << enl;
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