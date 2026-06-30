//已知一个比赛可以用一个由大写英文字母组成的字符串 s​ 来表示，其中每个字母代表一道题目。
//同时已知，如果字符串中包含连续子串 "FFT" 或 "NTT"，那么这个比赛就是困难的（difficult）。
//你的任务是重新排列比赛字符串 s​ 中的字符，使得这个比赛不再是困难的。如果初始比赛本身就不困难，你也可以保持原样不变。
//输入
//每组测试数据包含多个测试用例。第一行包含一个整数 t​ (1 ≤ t ≤ 10⁴) —— 测试用例的数量。接下来是测试用例的描述。
//每个测试用例的唯一一行包含字符串 s​ (1 ≤ |s| ≤ 2·10⁵)。
//关于输入数据的附加限制：
//所有测试用例中字符串的总长度不超过 2·10⁵。
//输出
//对于每个测试用例，输出一个字符串 —— 通过对 s​ 中的字母重新排列得到的非困难比赛字符串。
//如果存在多个正确答案，你可以输出任意一个。可以保证至少存在一个正确答案。
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
	list<char> lis(s.begin(), s.end());
	for (auto it = lis.begin(); it != lis.end(); ) { //不要在for循环里写it++
		if (*it == 'T') {
			char val = *it;  //保存 it 的值
			it = lis.erase(it); // erase 返回下一个有效迭代器，赋值给 it
			lis.push_front(val);
		} else {
			it++;
		}
	}
	for (auto it = lis.begin(); it != lis.end(); it++) {
		cout << *it;
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
