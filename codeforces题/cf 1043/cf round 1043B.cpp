// 瓦迪姆（Vadim）想好了一个数字 x。为了确保没人能猜到它，他在它的右侧追加了若干个（至少一个）0，从而得到一个新数字 y。
//然而，作为预防措施，瓦迪姆决定散布数字 n=x+y。对于给定的 n，找出瓦迪姆可能想到的所有符合条件的 x。
// 输入
// 每个测试包含多组测试用例。第一行包含一个整数 t（1≤t≤104）——测试用例的数量。接下来的行描述测试用例。
// 每个测试用例占一行，包含一个整数 n—— 瓦迪姆散布的数字（11≤n≤1018）。
// 输出
// 对于每个数字 n，如果没有符合条件的 x，输出 0。否则，输出符合条件的 x的数量，随后按升序输出所有符合条件的 x。
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

ll power(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

void solve(){
	ll n;
	cin >> n;
	int p = 0;
	ll x = n;
	while (x) {
		p++;
		x /= 10;
	}
	set<ll> res;
	for (int i = 1; i <= p; i++) {
		ll y = 1 + power(10, i);
		ll cur = n / y;
		if (n % y == 0) res.insert(cur);
	}
	if (res.empty()) {
		cout << 0 << enl;
		return;
	}
	cout << res.size() << enl;
	for (auto &i: res) {
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