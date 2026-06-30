// 弗拉德（Vlad）和迪马（Dima）在英语课上被分配了一项任务。他们得到两个字符串 a和 b，要求以任意顺序将 b中的所有字符追加到字符串 a中。两人决定分工合作，经过漫长的协商，确定了由谁来添加 b中的每个字符。
// 由于弗拉德的特殊性，他只能将字符添加到单词的开头，而迪马只能将字符添加到末尾。他们按照字符串 b中出现的顺序添加字符。你的任务是确定弗拉德和迪马最终得到的字符串是什么。
// 输入
// 每个测试包含多组测试用例。第一行包含一个整数 t（1≤t≤1000）——测试用例的数量。接下来是测试用例的描述。
// 对于每个测试用例：
// 第一行包含一个整数 n（1≤n≤10）——字符串 a的长度。
// 第二行包含字符串 a，由小写英文字母组成。
// 第三行包含一个整数 m（1≤m≤10）——字符串 b和 c的长度。
// 第四行包含字符串 b，由小写英文字母组成。
// 第五行包含字符串 c，由字符 'V'和 'D'组成——表示字符串 b的字符在迪马和弗拉德之间的分配情况。
// 如果 ci=’V’，则第 i个字母由弗拉德添加；否则，由迪马添加。
// 输出
// 对于每个测试用例，输出迪马和弗拉德工作完成后得到的字符串。
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

void solve(){
	int n, m; string a, b,c;
	cin >> n >> a >> m >> b >> c;
	int j = 0;
	for (int i = 0; i < (int)c.size(); i++, j++) {
		if (c[i] == 'V') {
			a = b[j] + a;
		} else {
			a = a + b[j];
		}
	}
	cout << a << enl;
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