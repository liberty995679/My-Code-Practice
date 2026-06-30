//有一次，Kirei 潜入了充满陷阱的 Ainzbern 家族庄园，但被 Kiritugu 的使魔发现。评估了自己的实力后，Kirei 决定撤退。庄园被表示为一棵有 n 个顶点的树，根节点是顶点 1。树的每个顶点上记录了一个数字 a[i]，表示顶点 i 的危险值。回忆一下，树是一个无环的连通无向图。
//为了成功撤退，Kirei 必须计算每个顶点的威胁值。一个顶点的威胁值等于从该顶点出发沿垂直路径（通向根节点 1 的路径）的最大交替和。
//从顶点 i 出发的垂直路径的交替和定义为：
//a[i] − a[p[i]] + a[p[p[i]]] − …
//其中 p[i] 是该路径上 i 的父节点（朝根的方向）。
//例如，在下方的树中，顶点 4 有以下垂直路径：
//[4]，交替和为 a[4] = 6；
//[4, 3]，交替和为 a[4] − a[3] = 6 − 2 = 4；
//[4, 3, 2]，交替和为 a[4] − a[3] + a[2] = 6 − 2 + 5 = 9；
//[4, 3, 2, 1]，交替和为 a[4] − a[3] + a[2] − a[1] = 6 − 2 + 5 − 4 = 5。
//顶点的危险值用红色标出。
//请帮助 Kirei 计算所有顶点的威胁值，并逃出庄园。
//输入格式​
//第一行包含一个整数 t（1 小于等于 t 小于等于 10 的 4 次方）—— 测试用例数量。
//接下来描述各测试用例。
//每个测试用例的第一行包含一个整数 n（2 小于等于 n 小于等于 2 乘 10 的 5 次方）—— 树的顶点数。
//第二行包含 n 个整数 a[1], a[2], …, a[n]（1 小于等于 a[i] 小于等于 10 的 9 次方）—— 各顶点的危险值。
//接下来的 n−1 行，每行包含两个整数 v, u（1 小于等于 v, u 小于等于 n，v 不等于 u）—— 描述树的一条边。
//保证所有测试用例的 n 之和不超过 2 乘 10 的 5 次方，且给定的边集构成一棵树。
//输出格式​
//对于每个测试用例，输出 n 个整数——每个顶点的威胁值。
#include <iostream>
#include <vector>
#include <algorithm>
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
vector<vector<ll>> g;
vector<ll> a;
vector<vector<ll>> dp;
void dfs(ll u, ll p) {  //树形dp
	dp[u][0] = a[u];
	dp[u][1] = -a[u];
	if (p != -1) {
		dp[u][0] = max(a[u], a[u] + dp[p][1]);  //dp[v][1]: 从 v 出发，v 的系数为负的最大交替和
		dp[u][1] = -a[u] + dp[p][0];           //dp[v][0]: 从 v 出发，v 的系数为正的最大交替和
	}
	for (ll v: g[u]) {
		if (v != p)	dfs(v, u);
	}
}

void solve() {
	ll n;
	cin >> n;
	a.assign(n + 1, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];
	g.assign(n + 1, vector<ll>());
	dp.assign(n + 1, vector<ll>(2, 0));
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << dp[i][0] << ' ';		
	}cout << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}