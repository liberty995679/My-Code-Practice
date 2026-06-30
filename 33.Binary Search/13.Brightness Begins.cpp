// 想象你有 n​ 盏灯，编号为 1, 2, …, n。初始时，所有灯都是亮着的。
// 翻转一盏灯的状态指的是：如果它原来是亮的就关掉，原来是关的就点亮。
// 接下来，你进行如下操作：
// 对于每个 i = 1, 2, …, n：
// 翻转所有满足 j 能被 i 整除​ 的灯 j 的状态 †。
// 在完成所有操作后，会有若干盏灯仍然亮着。
// 你的任务是：使得最终亮着的灯的数量恰好等于 k。
// 请找出最小的合适的 n，使得在执行完上述操作后，亮着的灯数恰好为 k。
// 可以证明，这样的答案总是存在的。
// † 若存在整数 z​ 使得 x = y·z，则称整数 x​ 能被 y​ 整除。
// 输入
// 每个测试包含多个测试用例。
// 第一行包含测试用例数 t（1 ≤ t ≤ 10⁴）。接下来是各测试用例的描述。
// 每个测试用例的唯一一行包含一个整数 k（1 ≤ k ≤ 10¹⁸）。
// 输出
// 对于每个测试用例，输出一个整数 n​ —— 满足条件的最小灯泡数量。
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

void solve(){
	ll k;
	cin >> k;
	ll l = 1; ll r = 2e18;  //就是找第k个非完全平方数 r初始2e18 因为 mid刚开始要 / 2
	while (l < r) {
		ll mid = (l + r) / 2;
		if (mid - (ll)sqrtl(mid) < k) { //sqrtl 比 sqrt 更精确 //double：≈ 1e-9 精度//long double：≈ 1e-18 精度
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << l << enl;
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