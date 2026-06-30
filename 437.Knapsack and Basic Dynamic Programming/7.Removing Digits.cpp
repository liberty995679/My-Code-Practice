//这是一个纯文本翻译版本的题目描述：
//给定一个整数 n。
//在每一步操作中，你可以从当前数字中减去它的某一位数字（十进制表示中的任意一位）。
//问：至少需要多少步操作，才能把这个数变成 0？
//输入​
//仅一行，包含一个整数 n。
//输出​
//输出一个整数：所需的最少步数。
//约束条件
//1 ≤ n ≤ 10⁶
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

vector<int> dig(ll n) {
	vector<int> a;
	while (n) {
		a.emplace_back(n % 10);
		n /= 10;
	}
	return a;
}

void solve() {
	int n;
	cin >> n;
	vector<ll> dp(n + 1, LLONG_MAX);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		vector<int> cur = dig(i);
		for (int j: cur) {
			if (i - j >= 0 && dp[i - j] != LLONG_MAX) {
				dp[i] = min(dp[i], dp[i - j] + 1);
			}
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