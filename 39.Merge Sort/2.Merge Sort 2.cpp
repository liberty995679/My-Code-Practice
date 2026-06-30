//归并排序
//输入n个数字 输出排序后的结果
//输出归并的次数，用函数递归
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
int cnt = 0;  //记录次数
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
		cnt++;
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
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
	mergesort(arr, 0, n);
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