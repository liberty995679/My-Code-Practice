//实现一个二分查找算法。
//输入
//输入的第一行包含整数 n 和 k（1 ≤ n, k ≤ 10^5），分别表示数组的长度和查询的次数。
//第二行包含数组的 n 个元素，数组按非递减顺序排列。第三行包含 k 个查询。所有数组元素和查询的值均为整数，其绝对值均不超过 10^9。
//输出
//对于每个查询，如果该数字出现在数组中，则在一行中输出 YES，否则输出 NO。
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

bool bin(const vector<int>& a, int k) {
	int l = 0;
	int r = a.size() - 1;
	int mid;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (a[mid] == k) {
			return true;
		} else if (a[mid] > k) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (a[l] == k) return true;
	return false;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < k; i++) {
		int p; cin >> p;
		if (bin(arr, p)) cout << "YES" << enl;
		else cout << "NO" << enl;
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