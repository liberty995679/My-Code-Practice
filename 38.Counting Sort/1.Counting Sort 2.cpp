//计数排序
//通常，当我们对一个列表进行排序时，排序的元素其实只是其他值的“钥匙”。举个例子，如果你想按文件大小排序文件，大小这个数字必须和对应的文件信息绑在一起。你不能只拿出大小数字排序然后输出，你得把所有相关的文件信息一起输出。
//计数排序适合用来排序整数列表。它不是通过比较大小来排序，而是创建一个整数数组，这个数组的索引范围覆盖了你要排序的所有值。
//每遇到原数组中的一个值，就把对应索引的计数器加一。最后，遍历这个计数数组，把每个非零索引的值打印对应次数。
//举个例子，假设有数组 。所有值都在  范围内，于是创建一个全零数组 。每一步的结果如下：
//i	arr[i]	result
//0	1	[0, 1, 0, 0]
//1	1	[0, 2, 0, 0]
//2	3	[0, 2, 0, 1]
//3	2	[0, 2, 1, 1]
//4	1	[0, 3, 1, 1]
//接下来，我们就可以打印排序后的数组了：。
//挑战
//给你一个无序的整数列表，使用计数排序方法对它进行排序，然后输出排序后的列表。
//提示：你可以用之前写过的计数代码，来按照顺序打印实际的值。
//函数说明
//请完成下面编辑器中的 countingSort 函数。它应该返回一个升序排序后的整数数组。
//countingSort 函数参数：
//arr：整数数组
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
	vector<int> cnt(101);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	for (int i = 0; i < cnt.size(); i++) {
		while (cnt[i]--) {
			cout << i << ' ';
		}
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