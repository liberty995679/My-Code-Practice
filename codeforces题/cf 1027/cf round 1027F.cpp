//给定一个整数 x 和一个整数 k。
//在一次操作中，你可以执行以下两种动作之一：
//选择一个整数 1 ≤ a ≤ k，令 x = x · a（乘法）；
//选择一个整数 1 ≤ a ≤ k，令 x = x / a（除法），且必须保证 x / a 是整数。
//求：使得 x 变为 y 所需的最少操作次数；如果无法实现，则判定为不可能。
//输入
//第一行包含一个整数 t（1 ≤ t ≤ 10^4）—— 测试用例的数量。
//每个测试用例仅有一行，包含三个整数 x、y 和 k（1 ≤ x, y, k ≤ 10^6）。
//保证所有测试用例中 x 的总和以及 y 的总和均不超过 10^8。
//输出
//对于每个测试用例：
//如果无法通过给定操作将 x 变为 y，输出 -1；
//否则，输出所需的最少操作次数。
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
unordered_map<int, int> dp;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int k;
int dfs(int x) {   //返回x变成1的最小步数
	if (x == 1) return 0;
	auto it = dp.find(x) ;
	if (it != dp.end()) return it->second;
	if (x <= k) return dp[x] = 1;
	int res = 1e9;
	for (int i = k; i > 1; i--) {
		if (x % i == 0) {
			res = min(res, dfs(x / i) + 1);
		}
	}
	return dp[x] = res;
} 

int check(int n) {  //判断 n 是否含有 > k 的质因数
	for (int i = 2; i * i <= n && i <= k; i++) {
		while (n % i == 0) {
			n /= i;
		}
	}
	if (n > k) return n; //  如果剩下的 n > k，说明它本身是一个 > k 的质数，无法被除掉，返回 n
	return 1; // 否则返回 1（说明所有质因数都 <= k）
}

void solve() {
	dp.clear();
	int x, y;
	cin >> x >> y >> k;
	if (check(x) != check(y)) {
		cout << -1 << enl;
		return;
	}
	int g = gcd(x, y);
	x = x / g;
	y = y / g;
	cout << dfs(x) + dfs(y) << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
    return 0;
}