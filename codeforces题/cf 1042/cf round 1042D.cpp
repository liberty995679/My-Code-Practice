//Kagari 正在准备归档一棵树，她知道成本取决于树的直径*。为了降低成本，她的目标是先将直径尽可能缩小。她可以对树进行以下操作：
//选择两个顶点 s 和 t。设从 s 到 t 的简单路径† 上的顶点序列为 v0, v1, …, vk，其中 v0 = s，vk = t。
//移除路径上的所有边，即移除边 (v0, v1), (v1, v2), …, (vk-1, vk)。
//将顶点 v1, v2, …, vk 直接连接到 v0，即添加边 (v0, v1), (v0, v2), …, (v0, vk)。
//可以证明，操作后图仍然是一棵树。
//请帮助她确定达到最小直径所需的最少操作次数。
//树的直径是任意一对顶点之间可能的最长距离。距离由连接它们的唯一简单路径上的边数来衡量。
//† 简单路径是树中两个顶点之间的路径，不重复访问任何顶点。可以证明，任意两个顶点之间的简单路径总是唯一的。
//输入格式​
//每个测试包含多个测试用例。第一行包含测试用例数量 t（1 小于等于 t 小于等于 10 的 4 次方）。接下来是各测试用例的描述。
//每个测试用例的第一行包含一个整数 n（2 小于等于 n 小于等于 2 乘 10 的 5 次方）—— 树的顶点数。
//每个测试用例接下来的 n-1 行描述树的结构。每行包含两个整数 u 和 v（1 小于等于 u, v 小于等于 n，u 不等于 v），表示顶点 u 和 v 之间有一条边。保证这些边构成一棵树。
//保证所有测试用例的 n 之和不超过 2 乘 10 的 5 次方。
//输出格式​
//对于每个测试用例，输出一个整数——使直径最小化所需的最少操作次数。
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

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> g(n + 1, vector<ll>());
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll ans = 0; ll mx_leave = 0;  //最大叶子数量
	for (int i = 1; i <= n; i++) {  //覆盖初始叶子集合
		if (g[i].size() > 1) {   //找深度大于1的叶子
			ll tmp = 0;
			for (auto v: g[i]) {
				tmp += (g[v].size() == 1); //叶子节点数量
			}
			ans += tmp;
			mx_leave = max(tmp, mx_leave); //优先选“叶子邻居最多”的那个点
		}
	}
	cout << ans - mx_leave << enl;
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