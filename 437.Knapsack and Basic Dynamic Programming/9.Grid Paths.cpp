//考虑一个大小为 n × n 的网格，其中某些格子可能设有陷阱。
//不能移动到有陷阱的格子。
//你的任务是计算从左上角格子到右下角格子的路径数量。
//在移动时，只能向右或向下走。
//输入
//第一行输入一个整数 n：表示网格的大小。
//接下来 n 行，每行包含 n 个字符，用于描述网格：
//.表示一个空单元格
//*表示一个陷阱
//输出
//输出路径数量对 10⁹ + 7​ 取模后的结果。
//约束条件
//1 ≤ n ≤ 1000
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
	int n;
	cin >> n;
	vector<string> g(n);
	for (int i = 0; i < n; i++) cin >> g[i];
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	dp[0][0] = (g[0][0] == '.' ? 1 : 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			if (i == 0 && j > 0) {
				if (g[i][j] == '.') dp[i][j] = dp[i][j - 1];
				else dp[i][j] = 0;
			}
			else if (j == 0 && i > 0) {
				if (g[i][j] == '.') dp[i][j] = dp[i - 1][j];
				else dp[i][j] = 0;
			} else {
				if (g[i][j] == '.') dp[i][j] = ((dp[i - 1][j]) % mod + (dp[i][j - 1]) % mod) % mod; 
				else dp[i][j] = 0;
			}
		}
	}
	cout << dp[n - 1][n - 1] << enl;
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