//考虑一个由 n 枚硬币组成的货币系统。每枚硬币都有一个正整数面值。你的任务是计算使用这些硬币，组成金额 x 的不同方式的数量。
//例如，如果硬币面值为 {2, 3, 5}，目标金额为 9，则有 8 种方式：
//2 + 2 + 5
//2 + 5 + 2
//5 + 2 + 2
//3 + 3 + 3
//2 + 2 + 2 + 3
//2 + 2 + 3 + 2
//2 + 3 + 2 + 2
//3 + 2 + 2 + 2
//输入
//第一行输入两个整数 n 和 x：硬币的种类数和目标金额。
//第二行输入 n 个不同的整数 c₁, c₂, …, cₙ：每种硬币的面值。
//输出
//输出一个整数：方案数对 10⁹ + 7 取模后的结果。
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
	vector<ll> v(n); 
	for (int i = 0; i < n; i++) cin >> v[i];
	vector<ll> dp(x + 1);
	dp[0] = 1;
	for (int j = 0; j <= x; j++) {  //先遍历金额 j，再遍历硬币
		for (int i: v) {
			if (j >= i) {
				dp[j] = (dp[j] + dp[j - i]) % mod;
			}
		}
	}
	cout << dp[x] << enl;
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