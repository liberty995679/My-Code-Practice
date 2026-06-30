//你被给定 n 个二进制堆，其中第 i 个堆由顶部的 a_i 个 0 和底部的 b_i 个 1 组成。
//在一次操作中，你可以取走任意堆的顶部元素，并将其移动到任意堆的任意位置（包括它原本所在的堆）。
//计算将各堆变为目标状态所需的最少操作次数，即使得第 i 个堆由顶部的 c_i 个 0 和底部的 d_i 个 1 组成。
//输入：
//每个测试包含多组测试用例。第一行包含测试用例的数量 t (1≤t≤10^4)。接下来是各个测试用例的描述。
//每个测试用例的第一行包含一个整数 n (1≤n≤2⋅10^5) —— 堆的数量。
//随后跟随 n 行，第 i 行包含四个整数 a_i, b_i, c_i, d_i (0≤a_i,b_i,c_i,d_i≤10^9) —— 表示第 i 个堆的初始状态和目标状态。
//保证存在一系列操作可以将这些堆转换为目标状态。
//保证所有测试用例中 n 的总和不超过 2⋅10^5。
//输出：
//对于每个测试用例，输出一个整数 —— 达到目标状态所需的最少操作次数。
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
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > c) {
			ans += a - c;
		}
		if (b > d) {
			ans += b - d + min(a, c);
		}
	}
	cout << ans << enl;
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
