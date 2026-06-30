//给你一个整数 n。
//称一个长度为 n 的数组 a 是 好数组，当且仅当：
//对所有 1 小于等于 i 小于 n，有 a[i] 乘 a[i+1] 小于 0（即相邻元素的乘积为负数，说明相邻元素符号相反）。
//对所有长度至少为 2 的子数组，其所有元素之和为正数。
//注：子数组是指原数组中连续的一段元素。
//注：正整数指 x 大于 0。
//此外，我们称一个长度为 n 的好数组 a 比另一个长度为 n 的好数组 b 更优，如果按绝对值构成的序列
//[|a[1]|, |a[2]|, ..., |a[n]|]在字典序上比[|b[1]|, |b[2]|, ..., |b[n]|]更小。
//这里 |z| 表示整数 z 的绝对值。
//你需要输出一个长度为 n 的好数组，它比任何其他好数组都更优。
//输入格式​
//第一行包含一个整数 t（1 小于等于 t 小于等于 500）—— 测试用例的数量。
//每个测试用例仅有一行，包含一个整数 n（2 小于等于 n 小于等于 2 乘 10 的 5 次方）—— 数组的长度。
//保证所有测试用例的 n 之和不超过 2 乘 10 的 5 次方。
//输出格式​
//对于每个测试用例，输出 n 个整数 a[1], a[2], ..., a[n]（负 10 的 9 次方 小于等于 a[i] 小于等于 10 的 9 次方），即你构造的数组，每个数占一行。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
 	ll n;
 	cin >> n;
 	ll cnt1 = 0 ; ll cnt0 = 0;
	vector<ll> a(n);
	if (n == 2) {
		cout << -1 << ' ' << 2 << enl;
		return;
	} 
	for (int i = 0; i < n; i++) {
		if (i % 2== 0) {
			a[i] = -1;
		} else {
			a[i] = 3;
		}
		if (i == n - 1 && n % 2 == 0) {
			cout << 2 << ' ';
			break;
		}
		cout << a[i] << ' ';
	}cout << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}