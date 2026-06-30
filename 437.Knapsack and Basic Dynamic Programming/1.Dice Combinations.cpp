//你的任务是计算通过掷骰子一次或多次，构造出总和 n 的方案数。每次掷骰子的结果都是 1 到 6 之间的整数。
//例如，若 n = 3，共有 4 种方式：
//1 + 1 + 1
//1 + 2
//2 + 1
//3
//输入
//输入仅一行，包含一个整数 n。
//输出
//输出方案数，对 10^9 + 7 取模后的结果。
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

void solve() {
	int mod = 1e9 + 7;
	int n; cin >> n;
	vector<int> dp(n + 1);   //dp[i]代表总方案数
	dp[0] = 1;  //什么都不扔也是一种方法凑零
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) {
				dp[i] = (dp[i] + dp[i - j]) % mod;
			}
		}
	}
	cout << dp[n] << enl;
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