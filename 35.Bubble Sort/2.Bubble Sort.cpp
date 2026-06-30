//FatalEagle 正在玩着 N 个方块，每个方块上都刻着一个独一无二的数字 T (0 \le T \le 256) 。
//他想学学怎么用冒泡排序把这些方块按从小到大的顺序排好。想了解冒泡排序的原理，可以点这里看看。
//输入说明
//第一行给出一个整数 N (0 \le N \le 20) 。
//第二行给出 N 个整数，数字之间用空格分开。
//输出说明
//先打印出初始的方块序列，然后每当冒泡排序交换了两个元素，就打印当前的方块序列。
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
		cout << arr[i] << ' ';
	}cout << enl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				cnt++;
				for (int k = 0; k < n; k++) {
					cout << arr[k] << ' ';
				}cout << enl;
			}
		}
	}
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