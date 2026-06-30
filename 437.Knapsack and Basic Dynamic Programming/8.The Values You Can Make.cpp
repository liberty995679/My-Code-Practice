//Pari 想从 Arya 那里买一块昂贵的巧克力。她有 n 枚硬币，第 i 枚硬币的面值是 ci。
//巧克力的价格是 k，因此 Pari 会选出总和为 k 的一部分硬币交给 Arya。
//看着这些硬币，她产生了一个疑问：在把这些硬币交给 Arya 之后，
//Arya 能用它们凑出哪些数值？她很嫉妒，不想让 Arya 能凑出太多不同的数值。
//所以她想知道：所有满足如下条件的数值 x —— 存在某个总和为 k 的硬币子集，使得 Arya 可以用这个子集中的一部分硬币凑出 x。
//换句话说：Pari 想知道所有满足以下条件的 x：存在某个总和为 k 的硬币子集，且该子集本身又存在一个子集，其总和为 x。
//也就是说，只要存在一种支付巧克力的方式，使得 Arya 能利用收到的硬币凑出 x，那么 x 就是合法的。
//输入
//第一行包含两个整数 n 和 k（1 ≤ n, k ≤ 500）—— 硬币的数量和巧克力的价格。
//下一行包含 n 个整数 c1, c2, ..., cn（1 ≤ ci ≤ 500）—— Pari 拥有的硬币面值。
//保证一定存在某种方式，使得硬币总和可以达到 k。
//输出
//输出的第一行包含一个整数 q —— 满足条件的 x 的个数。
//接下来在同一行（或第二行）输出 q 个整数，按升序排列​ —— 表示 Arya 能够用 Pari 支付的硬币子集所凑出的所有数值。
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
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];
	// dp[s] 是一个 bitset，dp[s][x] = true 表示总和为 s 的子集能凑出 x
	vector<bitset<501>> dp(k + 1);
	dp[0].set(0);
	for (int v: c) {
		for (int i = k; i >= 0; i--) {  // 倒序遍历 s，防止重复使用同一枚硬币（01背包经典写法）
			if (dp[i].any() && v + i <= k) {
				dp[v + i] |= dp[i];  // 1. 继承原来能凑出的所有 x（不用这枚硬币 c）
				dp[v + i] |= (dp[i] << v); // 2. 原来的 x 加 c（用这枚硬币 c）
			}
		}
	}
	vector<int> ans;
	for (int x = 0; x <= k; x++) {
		if (dp[k][x] == 1) {
			ans.push_back(x);
		}
	}
	cout << ans.size() << enl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
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