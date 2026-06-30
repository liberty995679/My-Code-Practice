//在二维平面上给定你 n 个点 (x_i, y_i)，其中 n 为偶数。请选择 n/2 个互不相交的点对 (a_i, b_i)
//以最大化所有点对内曼哈顿距离的总和。换句话说，最大化：
//∑{i=1}^{n/2} |x{a_i} − x{b_i}| + |y{a_i} − y_{b_i}|。
//输入：
//每个测试包含多组测试用例。第一行包含测试用例的数量 t (1≤t≤10^4)。接下来是各个测试用例的描述。
//每个测试用例的第一行包含一个偶整数 n (2≤n≤2⋅10^5) —— 点的数量。
//接下来的 n 行中，第 i 行包含两个整数 x_i 和 y_i (−10^6≤x_i,y_i≤10^6) —— 表示第 i 个点的坐标。
//保证所有测试用例中 n 的总和不超过 2⋅10^5。
//输出：
//对于每个测试用例，输出 n/2 行，第 i 行包含两个整数 a_i 和 b_i —— 表示第 i 个点对中两个点的索引。
//如果存在多种解法，输出其中任意一种即可。
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

struct Man {
	int a;
	int b;
	int id;
};

void solve() {
	int n;
	cin >> n;
	vector<Man> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].a >> a[i].b;
		a[i].id = i + 1;
	}
	sort(a.begin(), a.end(), [](const Man& a, const Man& b) {
		if (a.a != b.a) return a.a < b.a;
		return a.b < b.b;
	});
	int k = n / 2; //分成两部分
	vector<Man> L(a.begin(), a.begin() + k);
	vector<Man> R(a.begin() + k, a.end());
	sort(L.begin(), L.end(), [](const Man& a, const Man& b){
		return a.b < b.b;
	});
	sort(R.begin(), R.end(), [](const Man& a, const Man&b){
		return a.b < b.b;
	});
	for (int i = 0; i < k; i++) {
		cout << L[i].id << ' ' << R[k - i - 1].id << enl;
	}
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
