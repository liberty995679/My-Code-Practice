//归并排序
//t个用例 输入n个数字 
//计算逆序对的数量
//如果 i < j 且 A[i] > A[j]，那么对 (i, j) 被称为 A 的一个逆序对。
// 给定 n 和数组 A，你的任务是找出 A 的逆序对数量。
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
using ll = long long;
const char enl = '\n';
ll cnt = 0;  //记录次数
void Merge(vector<int> &a, int left, int mid, int right) {
	int n1 = mid - left;  //左边几个数
	int n2 = right - mid; //右边几个数
	vector<int> L(n1 + 1), R(n2 + 1);
	for (int i = 0; i < n1; i++) {
		L[i] = a[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = a[mid + i];
	}
	L[n1] = INT_MAX; R[n2] = INT_MAX;
	int i = 0; int j = 0;
	for (int k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			cnt += n1 - i; //当从右边取数时，左边还有 (n1 - i) 个数没处理
			j++;
		}
	}
}

void mergesort(vector<int>& a, int left, int right) {
	if (right - left >= 2) { //至少有2个数
		int mid = left + (right - left) / 2;
		mergesort(a, left, mid);
		mergesort(a, mid, right);
		Merge(a, left, mid, right);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cnt = 0;
	mergesort(arr, 0, n);
	cout << cnt << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}