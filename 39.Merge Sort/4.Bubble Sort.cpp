//归并排序
//现在，给你一个包含 N 个整数的数组，你需要计算如果用冒泡排序对它进行排序，会发生多少次交换操作。
//输入格式
//输入第一行是一个整数 T (1 ≤ T ≤ 100)，表示测试用例的数量。
//接下来有 T 组测试数据。每组测试数据第一行是一个整数 N (1 ≤ N ≤ 10000)，表示数组中整数的个数，第二行包含 N 个以空格分隔的 32 位整数。
//输出格式
//对于每组测试数据，输出一行，格式为 Case X: Y，
//其中 X 是测试用例编号，Y 是冒泡排序过程中发生的交换次数对 10000007 取模后的结果。
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
const int mod = 1e7 + 7;   //这题考察的是归并排序，用冒泡排序会超时
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
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			cnt = (cnt + (n1 - i) % mod) % mod; //当从右边取数时，左边还有 (n1 - i) 个数没处理
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
int tt = 1;
void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cnt = 0;
	mergesort(arr, 0, n);
	cout << "Case " << tt++ << ": ";
	cout << cnt << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}