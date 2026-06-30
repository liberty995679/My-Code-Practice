//归并排序
//输入n个数字 输出排序后的结果
#include <iostream>
#include <algorithm>
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
const char enl = '\n';

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int mid = n / 2;
	vector<int> a(arr.begin(), arr.begin() + mid);
	vector<int> b(arr.begin() + mid, arr.end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> ans;
	int i = 0; int j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i] < b[j]) {
			ans.push_back(a[i]);
			i++;
		} else {
			ans.push_back(b[j]) ;
			j++;
		}
	}
	while (i < a.size()) {
		ans.push_back(a[i]);
		i++;
	}
	while (j < b.size()) {
		ans.push_back(b[j]);
		j++;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] <<' ';
	}cout << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}