//选择排序
//输入n个元素 输出每一个交换后的数组和交换次数
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
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int mn = i;
		for (int j = i; j < n; j++) {
			if (arr[j] < arr[mn]) {
				mn = j;
			}
		}
		if (mn != i) {
			swap(arr[i], arr[mn]);
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << ' ';
		cout << arr[i];
	}cout << enl;
	cout << cnt << enl;
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