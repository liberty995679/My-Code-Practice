//在回收中心有 n 个垃圾袋，第 i 个垃圾袋的重量为 ai。
//每一秒钟会依次发生两个动作：
//首先，你必须选择一个垃圾袋并将其销毁。如果该垃圾袋的重量严格大于 c，则需要花费 1 枚硬币，否则花费 0 枚硬币。
//然后，其余所有剩余垃圾袋的重量都会变为原来的两倍。
//你需要花费的最少硬币数量是多少，才能销毁所有垃圾袋？
//输入
//每个测试包含多组测试用例。第一行包含测试用例的数量 t (1≤t≤1000)。接下来是对测试用例的描述。
//每个测试用例的第一行包含两个整数 n 和 c (1≤n≤30，1≤c≤10^9)。
//每个测试用例的第二行包含 n 个整数 a1,a2,…,an (1≤ai≤10^9) —— 表示每个垃圾袋的重量。
//输出
//对于每个测试用例，输出一个整数 —— 销毁所有垃圾袋所需的最少硬币数量。
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
	ll n, c;
	cin >> n >> c;
	set<int> s;
	vector<ll> arr;
	int cost = 0;
	priority_queue<ll> pq;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x > c) cost++;
		else pq.push(x);
	}
	int k = 1;
	while (!pq.empty()) {
		ll top = pq.top(); pq.pop();
		top *= k;
		if (top <= c) {
			k *= 2;
		} else {
			cost++;
		}
	}
	cout << cost << enl;
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
