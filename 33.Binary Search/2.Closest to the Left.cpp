//给定一个由 n 个数组成的数组，数组已按非递减顺序排列，以及 k 个查询。对于每个查询，输出数组中不大于给定值的最大元素的下标。
//输入
//输入的第一行包含整数 n 和 k（0 < n, k ≤ 10^5），分别表示数组的长度和查询的次数。
//第二行包含数组的 n 个元素，数组按非递减顺序排列。第三行包含 k 个查询。所有数组元素和查询均为整数，其绝对值均不超过 2·10^9。
//输出
//对于每个查询，输出数组中不大于给定值的最大元素的下标。如果不存在这样的元素，输出 0。
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
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < k; i++) {
		ll p; cin >> p;
		int pos = upper_bound(arr.begin(), arr.end(), p) - arr.begin();
		cout << pos << enl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
    return 0;
}