// 在一个无限大的网格中，有一个机器人位于单元格 (a, b)。Misha 想把它移动到单元格 (0, 0)。为此，他已经固定了一个整数 k。
// Misha 可以执行以下操作：选择两个整数 dx 和 dy（两者都在 0 到 k 之间，包含边界），
// 将机器人向左移动 dx 个单元格（沿 x 坐标减小的方向），并向下移动 dy 个单元格（沿 y 坐标减小的方向）。
// 换句话说，就是将机器人从 (x, y) 移动到 (x − dx, y − dy)。
// 该操作的成本（cost）定义为：
// 1，如果选择的这对 (dx, dy) 是第一次被使用；
// 0，如果这对 (dx, dy) 之前已经被选择过。
// 注意，如果 dx ≠ dy，那么 (dx, dy) 和 (dy, dx) 被视为不同的组合。
// 请帮助 Misha 以最小的总成本将机器人带到单元格 (0, 0)。注意，你不需要最小化操作次数。
// 输入
// 第一行包含一个整数 t (1 ≤ t ≤ 10^4) —— 测试用例的数量。
// 每个测试用例的唯一一行包含三个整数 a, b 和 k (1 ≤ a, b, k ≤ 10^18)。
// 输出
// 对于每个测试用例，输出一个整数 —— 将机器人移动到单元格 (0, 0) 所需的最小总操作成本。
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

ll gcd(ll a, ll b) {
	while (b) {
		ll t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void solve() {
	ll a, b, k;
	cin >> a  >> b >> k;
	ll g = gcd(a, b);
	ll dx = a / g;  //除以最大公约数得到的数
	ll dy = b / g;  //a = g * dx , b = g * dy
	if (k >= dx && k >= dy) {
		cout << 1 << enl;
	} else {
		cout << 2 << enl;
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
