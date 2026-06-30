// 这是本题的简单版本。简单版本与困难版本的区别在于：简单版本要求在交易次数最少的前提下确定最小花费，而困难版本要求在限定交易次数的前提下确定最小花费。
// 在一个狡猾的商贩用三个西瓜顶替一个西瓜卖出去之后，他决定进一步增加利润——具体来说，他进了更多的西瓜。现在，他出售 3x个西瓜要收取 3x+1+x⋅3x−1枚硬币的费用，
// 其中 x是一个非负整数。这样的销售被称为一次“交易”（deal）。
// 一位精明的买家找到了他，但这位买家的时间极其紧迫。因此，他想恰好购买 n个西瓜，并且要尽可能少地进行交易（即最少的交易次数）。
// 由于买家很匆忙，他向你求助，希望你能算出：为了购买 n个西瓜，考虑到他会采用交易次数最少的方案，他最少需要支付多少硬币给卖家。
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
	ll n;
	cin >> n;
	ll ans = 0;
	int x = 0;
	while (n > 0) {
		int k = n % 3;
		ans += k * cost[x];
		n /= 3;
		x++;
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
	unit();
	while (t--) {
		solve();
	}
	return 0;
}