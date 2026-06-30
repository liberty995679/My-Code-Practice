//你被给定了一家餐厅中 n 位顾客的到达和离开时间。
//请问在任何时刻，餐厅里最多有多少位顾客？
//输入​
//第一行有一个整数 n：表示顾客的数量。
//接下来有 n 行，每行描述一位顾客。每行有两个整数 a 和 b：分别表示该顾客的到达时间和离开时间。
//你可以假设所有到达和离开时间都是不同的。
//输出​
//输出一个整数：表示任意时刻餐厅内的最大顾客数量。
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
#include <bitset>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
	int n;
	cin >> n;
	vector<pair<ll, int>> arr;
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		arr.push_back({a, 1});
		arr.push_back({b, -1});
	}
	sort(arr.begin(), arr.end());
	ll ans = 0;
	ll cur=  0;
	for (auto i: arr) {
		cur += i.second;
		ans = max(ans, cur);
	}
	cout << ans << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	solve();
    return 0;
}