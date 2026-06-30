//素数是一个正整数，恰好只有两个约数：1 和它自身。前几个素数是 2,3,5,7,11,…
//正整数的素因数分解是指将其表示为若干个素数的乘积。例如：
//111 的素因数分解是 3⋅37；
//43 的素因数分解是 43；
//12 的素因数分解是 2⋅2⋅3。
//对于每个正整数，其素因数分解是唯一的（如果不考虑乘积中素数的顺序）。
//如果某个正整数在其分解中出现的所有素数都至少包含两位数字，我们就称其为“好整数”。例如：
//343=7⋅7⋅7 不是好整数；
//111=3⋅37 不是好整数；
//1111=11⋅101 是好整数；
//43=43 是好整数。
//你需要计算从 l 到 r（包含端点）之间好整数的数量。
//输入
//第一行包含一个整数 t (1≤t≤10³) —— 表示测试用例的数量。
//每个测试用例占一行，包含两个整数 l 和 r (2≤l≤r≤10¹⁸)。
//输出
//对于每个测试用例，输出一个整数 —— 表示从 l 到 r 的好整数数量。
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

ll culculate(ll r) {  //计算倍数,容斥原理
	ll ans = r;  //一开始是总数r
	vector<int> nums1 = {2, 3, 5, 7, 30, 105, 42, 70}; //相加a  a3
	vector<int> nums2 = {6, 10, 14, 15, 21, 35, 210}; // 相减a2  a4
	for (int i: nums1) {
		ans -= r / i;   //计算r有多少个i的倍数 向下取整
	}
	for (int i: nums2) {
		ans += r / i;
	}
	return ans;
}

void solve() {
	ll l, r;   //计算所有2 3 5 7 的倍数的数 减去即可
	cin >> l >> r;
	cout << culculate(r) - culculate(l - 1) << enl;
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
