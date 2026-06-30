//印度夏天是一年中非常美丽的时光！一个名叫 Alyona 的女孩正在森林里散步，并用落叶采集成一个花束。
//Alyona 非常挑剔——如果一片叶子的颜色和树种与她已经有的一片叶子完全相同，她就不会再拿这片叶子。请你计算 Alyona 最终采集了多少片叶子。
//输入格式
//第一行包含一个整数 n（1≤n≤100）——Alyona 发现的叶子数。
//接下来的 n 行，每行描述一片叶子。每片叶子的描述由树种和颜色组成，两者都是只含有不超过 10 个小写英文字母的字符串。名字不能为空串。每行中树种与颜色用一个空格分隔。
//输出格式
//输出一个整数——Alyona 最终采集的叶子数量。
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
	set<pair<string, string>> s;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		s.insert({a, b});
	}
	cout << s.size() << enl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	solve();
    return 0;
}