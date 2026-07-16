// 给定一个长度为 n 的排列 p 和一个长度为 n 的数组 a。
// 如果可以通过对排列 p 执行若干次（可能为 0 次）如下操作得到数组 a，则称排列 p 可生成数组 a。
// 一次操作可以选择一个下标 i 满足 1 <= i < n，并执行以下两种替换之一：将 p_i 赋值为 p{i+1}，或将 p{i+1} 赋值为 p_i。
// 换句话说，一次操作中你可以选择数组中两个相邻元素，并将其中一个的值复制到另一个上。
// 你需要判断排列 p 是否可以生成数组 a。
// 排列的定义为：由 n 个从 1 到 n 的互不相同的整数按任意顺序排列组成的数组。
// 例如 [2,3,1,5,4] 是排列，而 [1,2,2] 不是（数字 2 重复出现），[1,3,4] 也不是（n=3 但出现了数字 4）。
// 输入包含多组测试用例。
// 第一行给出测试用例数 t（1 <= t <= 10^4），随后依次给出每组用例。
// 每组第一行给出一个整数 n（2 <= n <= 2 * 10^5），表示数组和排列的长度。
// 第二行给出 n 个整数 p1, p2, ..., pn（1 <= pi <= n），表示排列的元素。
// 第三行给出 n 个整数 a1, a2, ..., an（1 <= ai <= n），表示数组的元素。
// 保证所有测试用例中 n 的总和不超过 2 * 10^5。
// 对于每组测试用例，如果排列 p 可生成数组 a，输出 YES，否则输出 NO。
// 输出字母大小写不限，例如 yEs、yes、Yes、YES 均可视为正确回答。
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

bool concert(vector<int> &p, vector<int> &b) {
	int n = p.size();
	int m = b.size();
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (p[i] == b[j]) {
			i++;
			j++;
		}
		else i++;
	}
	return j == m;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> b;
	for (int x : a) {
		if (b.empty() || b.back() != x) {
			b.push_back(x);
		}
	}
	if (concert(p, b)) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
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