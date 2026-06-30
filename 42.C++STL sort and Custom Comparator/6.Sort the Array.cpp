//作为一个程序员，你非常喜欢数组。为了庆祝你的生日，朋友们送给你一个由 n 个互不相同的整数组成的数组 a。
//不幸的是，这个数组 a 的大小太小了。你想要一个更大的数组！朋友们同意给你一个更大的数组，但前提是你必须正确回答下面这个问题：
//是否可以通过仅反转数组 a 的一个连续段，使整个数组按升序排列？​
//关于“段”和“反转”的定义，见题目说明。
//输入​
//第一行输入一个整数 n（1 ≤ n ≤ 10⁵）—— 数组 a 的长度。
//第二行包含 n 个互不相同的空格分隔的整数：a[1], a[2], ..., a[n]（1 ≤ a[i] ≤ 10⁹）。
//输出​
//根据答案输出 "yes"或 "no"（不带引号）。
//如果答案是 "yes"，则还需输出两个空格分隔的整数，表示要反转的段的起始和结束索引（start 不能大于 end）。
#include <iostream>
#include <algorithm>
#include <sstream>
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

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	vector<int> b = arr;
	sort(b.begin(), b.end());
	int l = 1;
	int r = n;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i + 1]) {
			l = i;
			break;
		}
	}
	for (int i = l; i < n; i++) {
		if (arr[i] < arr[i + 1]) {
			r = i;
			break;
		}
	}
	sort(arr.begin() + l, arr.begin() + r + 1);
	if (arr == b) {
		cout << "yes" << enl;
		cout << l << ' ' << r <<enl;
	} else {
		cout << "no" << enl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	solve();
    return 0;
}