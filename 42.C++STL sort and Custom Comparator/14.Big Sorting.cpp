//考虑一个由数字字符串组成的数组，其中每个字符串是一个正整数，长度从 1 到任意位数不等。
//请将数组元素按它们所表示的整数值的非递减（即升序）排序，并返回排序后的数组。
//示例​
//返回数组 ['1', '3', '150', '200']。
//函数说明​
//在编辑器中完成 bigSorting函数。
//bigSorting有以下参数：
//string unsorted[n]：一个未排序的整数字符串数组
//返回值：string[n]：按数值大小排序后的数组
//输入格式​
//第一行包含一个整数 n，表示数组的长度。
//接下来的 n 行，每行包含一个整数字符串。
//约束条件​
//每个字符串都保证表示一个正整数。
//没有前导零。
//所有字符串的位数总和在 1 到 10^6 之间（含）。
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

struct BigInt{
	vector<ll> a;
	BigInt(string num) {
		a.clear();
		for (int i = num.size() - 1; i >= 0; i--) {
			a.push_back(num[i] - '0');
		}
	}
	void point() {
		for (int i = a.size() - 1; i >= 0; i--) {
			cout << a[i];
		}cout << enl;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<BigInt> arr;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr.push_back(s) ;
	}
	sort(arr.begin(), arr.end(), [](const BigInt& x, const BigInt& y){
		if (x.a.size() != y.a.size()) return x.a.size() < y.a.size();
		for (int i = x.a.size() - 1; i >= 0; i--) {
			if (x.a[i] != y.a[i]) {
				return x.a[i] < y.a[i];
			}
		}
		return false;
	});
	for (auto& i: arr) {
		i.point();
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