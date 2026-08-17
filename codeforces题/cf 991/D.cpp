// 给你一个由数字0到9组成的字符串s。
// 在一次操作中，你可以选择字符串中的任意一个数字（不能是0，也不能是最左边的数字），将其减1，然后将其与左侧相邻的数字交换位置。
// 例如，对字符串1023进行一次操作，你可以得到1103或1022。
// 求经过任意次操作后，你能得到的字典序最大的字符串。
// 输入格式
// 输入的第一行包含一个整数t（1 ≤ t ≤ 10^4）——表示测试用例的数量。
// 每个测试用例只有一行，包含一个数字字符串s（1 ≤ |s| ≤ 2·10^5），其中|s|表示字符串s的长度。该字符串没有前导零。
// 保证所有测试用例的|s|之和不超过2·10^5。
// 输出格式
// 对于每个测试用例，在单独的一行中输出答案。
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
	string s;
	cin >> s;
	vector<int> arr;
	for (char c: s) arr.push_back(int(c) - int('0'));
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n && j <= i + 9; j++) {
			int cur = arr[j] - (j - i);
			if (cur > arr[i]) {
				for (int p = j; p > i; p--) {
					arr[p] = arr[p - 1];
				}
				arr[i] = cur;
			}
		}
	}
	string res = "";
	for (int i = 0; i < n; i++) res += to_string(arr[i]);
	cout << res << enl;
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