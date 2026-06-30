//插入排序
//写一个插入排序算法的程序，将序列 A 按升序排列。算法应基于以下伪代码实现：
//for i = 1 to A.length-1
//    key = A[i]
//    /* 将 A[i] 插入到已排序序列 A[0,...,j-1] 中 */
//    j = i - 1
//   while j >= 0 and A[j] > key
//        A[j+1] = A[j]
//        j--
//    A[j+1] = key
//注意，数组元素的索引从 0 开始计数。
//为了更好地展示算法过程，你的程序需要输出每一步的中间结果。
//输入
//第一行输入一个整数 N，表示序列中元素的个数。
//第二行输入 N 个元素，元素之间用单个空格分隔。
//输出
//输出共 N 行，每行输出一步排序后的序列，元素之间用单个空格分隔。
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
	for (int i = 0; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		for (int i = 0; i < n; i++) {
			if (i > 0) cout << ' ';
			cout << arr[i];
		}cout << enl;
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