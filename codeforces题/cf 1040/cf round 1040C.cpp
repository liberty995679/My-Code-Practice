//对于一组数对 S = {(a1, b1), (a2, b2), …, (am, bm)}，其中对于所有 1 ≤ i ≤ m 都有 ai < bi，我们按如下方式定义 f(S) 和 g(S)：
//将每个 (ai, bi) 视为数轴上的一个区间，f(S) 是这些区间并集的长度。更形式化地说，f(S) 是满足存在某个 i（1 ≤ i ≤ m）使得 [x, x+1] 包含于 [ai, bi] 的整数 x 的数量。
//将每个 (ai, bi) 视为图中的一条无向边，g(S) 是至少位于一个含至少 3 条边的简单环上的节点数量。更形式化地说，g(S) 是满足存在路径 x1 → x2 → … → xk → x1 的节点 x1 的数量，其中 k ≥ 3 且所有 x1, x2, …, xk 互不相同。
//例如，对于 S = {(1,2), (2,4), (1,4), (4,5), (6,7)}，可得 f(S) = 5 且 g(S) = 3。
//给定 n 个互不相同的数对，你的任务是选择这些数对的一个子集 S'，使得 f(S') - g(S') 最大化。你需要输出所选数对的索引。
//输入
//每个测试包含多个测试用例。第一行包含测试用例的数量 t（1 ≤ t ≤ 10^4）。接下来是每个测试用例的描述。
//每个测试用例的第一行包含一个整数 n（1 ≤ n ≤ 3·10^3）。
//接下来 n 行，每行包含两个整数 ai 和 bi（1 ≤ ai < bi ≤ 2n），表示一个数对。
//保证同一测试用例中的所有数对互不相同。
//保证所有测试用例的 n² 之和不超过 9·10^6。
//输出
//对于每个测试用例，第一行包含一个整数 k（0 ≤ k ≤ n）—— 子集 S' 的大小。
//第二行包含 k 个整数 i1, i2, …, ik（1 ≤ i1, i2, …, ik ≤ n）—— 所选数对的索引。注意索引必须互不相同。
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
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	vector<int> tag(n + 1, 1);  //一开始默认全选
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue; 
			if (a[j] <= a[i] && b[i] <= b[j]) tag[i] = 0; //完全包含的区间不选
		}
		if (tag[i]) ans.push_back(i);  //要选的区间放入ans
	}
	cout << ans.size() << enl;
	for (int i: ans) {
		cout << i << ' ';
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