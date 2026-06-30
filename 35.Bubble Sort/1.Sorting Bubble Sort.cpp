//给定一个整数数组，请使用上述冒泡排序算法将数组按升序排序。排序完成后，输出以下三行：
//Array is sorted in numSwaps swaps.其中 numSwaps是排序过程中发生的交换次数。
//First Element: firstElement其中 firstElement是排序后数组的第一个元素。
//Last Element: lastElement其中 lastElement是排序后数组的最后一个元素。
//小提示：要完成本题，你需要添加一个变量来记录整个算法运行过程中的交换总次数。
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
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				cnt++;
			}
		}
	}
	cout << "Array is sorted in " << cnt << " swaps." <<enl;
	cout << "First Element: " << arr[0] << enl;
	cout << "Last Element: " << arr[n - 1] << enl;
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