// 这是本题困难版本的纯文本翻译。同样，我已根据数学题的常规表述，将原文中缺失下标的 3x补全为 3^x和 3^{x-1}，以确保题意清晰准确。
// 这是本题的困难版本。简单版本与困难版本的区别在于：简单版本要求在交易次数最少的前提下确定最小花费，而困难版本要求在限定交易次数的前提下确定最小花费。
// 在一个狡猾的商贩用三个西瓜顶替一个西瓜卖出去之后，他决定进一步增加利润——具体来说，他进了更多的西瓜。现在，他出售 3
// 枚硬币的费用，其中 x是一个非负整数。这样的销售被称为一次“交易”（deal）。
// 一位精明的买家找到了他，但这位买家时间不多，因此他最多只能进行 k次交易，并且计划恰好购买 n个西瓜。
// 买家很匆忙，因此向你求助，希望算出：如果他最多进行 k次交易，为了购买 n个西瓜，他最少需要支付多少硬币。如果无法在满足所有条件的情况下恰好买到 n个西瓜，请输出 −1。
// 输入
// 第一行包含一个整数 t(1≤t≤10
// ) —— 测试用例的数量。随后是测试用例的描述。
// 每个测试用例的单行中包含两个整数 n和 k(1≤n,k≤10
// ) —— 需要购买的西瓜数量以及可以进行的最大交易次数。
// 输出
// 对于每个测试用例，输出一个整数 —— 西瓜的最小花费；如果无法在满足条件的情况下买到西瓜，则输出 −1。
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
vector<ll> cost(22);
vector<ll> pows(22);
void unit() {
	cost[0] = 3;
	pows[0] = 1;
	for (int i = 1; i <= 20; i++) {
		pows[i] = pows[i - 1] * 3;
		cost[i] = pows[i - 1] * (9 + i);
	}
}

void solve(){
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	int x = 0;
	int cnt = 0;
	if (k >= n) {
        cout << 3 * n << '\n';
        return;
    }
	int num = n;
	while (num > 0) {
		int t = num % 3;
		ans += t * cost[x];
		cnt += t;
		num /= 3;
		x++;
	}
	if (cnt > k) {
		cout << -1 << enl;
		return;
	}
	 // 三进制拆分
    vector<ll> digits;
    ll temp = n;
    while (temp > 0) {
        digits.push_back(temp % 3);
        temp /= 3;
    }
	int len = digits.size();
	ll cur = ans;
	int times = cnt;
	vector<ll> d = digits;
	for (int i = len - 1; i >= 1; i--) {
		int max_s = min(d[i], (k - times) / 2); //每次拆解需要增加 2 次交易，所以最多能拆 (k - cur_times) / 2 次)(整除)
		if (max_s > 0) {
			d[i] -= max_s;
			d[i - 1] += max_s * 3;
			times += 2 * max_s;
			cur += (3 * cost[i-1] - cost[i]) * max_s;
		}
	}
	cout << cur << enl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	unit();
	while (t--) {
		solve();
	}
	return 0;
}