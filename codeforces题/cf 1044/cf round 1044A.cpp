// 史蒂夫偶然发现了 n 个齿轮的集合，其中第 i 个齿轮有 ai 个齿，他想把它们排成一排。
// 在他排列好之后，史蒂夫将以每秒 1 转的速度转动最左边的齿轮。对于每个其他齿轮，设 x 是它的齿数，y 是其左侧齿轮的齿数，z 是其左侧齿轮的转速。那么，它的转速将是 (y/x) * z 转每秒。
// 如果最右边的齿轮以每秒 1 转的速度旋转，史蒂夫就认为这个装置令人满意。请判断史蒂夫能否重新排列这些齿轮，组成一个令人满意装置。
// 输入
// 每个测试包含多个测试用例。第一行包含测试用例的数量 t (1≤t≤1000)。接下来是对测试用例的描述。
// 每个测试用例的第一行包含一个整数 n (2≤n≤100) —— 史蒂夫拥有的齿轮数量。
// 每个测试用例的第二行包含 n 个整数 a1, a2, …, an (2≤ai≤100) —— 每个齿轮的齿数。
// 输出
// 对于每个测试用例，如果史蒂夫能以令人满意的方式重新排列齿轮，打印“YES”，否则打印“NO”。
// 你可以以任意大小写（大写或小写）输出答案。例如，字符串 "yEs"、"yes"、"Yes" 和 "YES" 都会被识别为肯定的回答。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
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
string s = " ";

void solve() {
	int n;
	cin >> n;
	set<int> s;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (s.count(x)) flag = true;
		s.insert(x);
	}
	if (flag) cout << "YES" << enl;
	else cout << "NO" << enl;
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