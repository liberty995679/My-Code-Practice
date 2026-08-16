// 给你一个数字 n，它的长度不超过 10^5。
// 你可以进行以下操作任意多次：选择这个数字中的某一位，将其平方，并用结果替换原来的那一位。替换后的结果必须仍然是一个数字（也就是说，如果你选择的数字是 x，那么 x^2 的值必须小于 10）。
// 问：通过这些操作，能否得到一个能被 9 整除的数字？
// 输入
// 第一行包含一个整数 t（1 ≤ t ≤ 10^4）—— 测试用例的数量。
// 每个测试用例的唯一一行给出数字 n，没有前导零。数字的长度不超过 10^5。
// 保证所有测试用例中数字的长度之和不超过 10^5。
// 输出
// 对于每个测试用例，如果可以通过上述操作得到一个能被 9 整除的数字，输出 "YES"，否则输出 "NO"。
// 每个字母可以用任意大小写输出。例如，字符串 "yEs"、"yes"、"Yes" 和 "YES" 都会被接受为正答案。
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
	ll sum =  0;
	int cnt2 = 0;
	int cnt3 = 0;
	for (char c : s) {
		if (c == '2') cnt2++;
		if (c == '3') cnt3++;
		sum += c - '0';
	}
	if (sum % 9 == 0) {
		cout << "YES" << enl;
		return;
	}
	for (int a = 0; a <= min(cnt2, 9); a++) {  //(sum + 2a + 6b) % 9 == 0
		for (int b = 0; b <= min(cnt3, 9); b++) {
			if ((sum + 2 * a + 6 * b ) % 9 == 0) {
				cout << "YES" << enl;
				return;
			}
		}
	}
	cout << "NO" << enl;
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