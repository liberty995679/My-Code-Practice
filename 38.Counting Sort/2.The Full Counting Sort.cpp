//用计数排序对一组字符串和整数的配对进行排序。如果两个字符串对应的整数相同，输出时必须保持它们原来的顺序，也就是说，你的排序算法要做到 稳定。这里还有个小花样：数组前半部分的字符串要全部替换成字符 - （破折号，ASCII 码45）。
//插入排序和简单版快速排序是稳定的，但快速排序的原地优化版本就不稳定，因为它排序时会乱调元素位置。
//请设计一个稳定的计数排序算法。
//举个例子
//前两个字符串被替换成了 '-'。因为最大整数是 ，所以准备一个至少包含三个空数组的辅助数组。下面展示了插入过程：
//i	string	converted	list
//0				[[],[],[]]
//1 	a 	-		[[-],[],[]]
//2	b	-		[[-],[-],[]]
//3	c			[[-,c],[-],[]]
//4	d			[[-,c],[-,d],[]]
//最后输出结果是： 。
//函数说明
//请完成下面的 countSort 函数，构造并打印排序后的字符串。
//countSort 的参数如下：
//string arr[n][2]: 每个 arr[i] 包含两个字符串，分别是 x 和 s
//返回值
//- 打印排序后的字符串，元素之间用空格分开。
//注意：每个 、 的第一个元素需要转换成整数来排序。
//输入格式
//第一行是 ，表示整数/字符串对的数量 。
//接下来  行，每行包含  和 ，分别是整数（以字符串形式）和对应的字符串。
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
	vector<vector<string>> cnt(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> arr[i] >> s;
		if (i < n / 2) {
			cnt[arr[i]].push_back("-") ;
		} else {
			cnt[arr[i]].push_back(s);
		}
	}
	for (int i = 0; i < cnt.size(); i++) {
		for (auto it: cnt[i]) {
			cout << it << ' ';
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