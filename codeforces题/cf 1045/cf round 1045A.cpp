// 你有三个正整数 n、a和 b（1≤a,b≤n）。
// 考虑一排 n个格子，初始全部为白色，编号从 1到 n。你将按顺序执行以下两个步骤：
// 选择一个整数 x，使得 1≤x≤n−a+1，并将连续的 a个格子 x,x+1,…,x+a−1涂成红色。
// 选择一个整数 y，使得 1≤y≤n−b+1，并将连续的 b个格子 y,y+1,…,y+b−1涂成蓝色。
// 如果一个格子既被涂成红色又被涂成蓝色，其最终颜色为蓝色。
// 如果对于每个从 1到 n（包含）的整数 i，格子 i的颜色都与格子 n+1−i的颜色相同，则称该网格的着色是对称的。你的任务是判断是否存在整数 x和 y，使得网格的最终着色是对称的。
// 输入
// 每个测试包含多组测试用例。第一行包含测试用例的数量 t（1≤t≤500）。接下来是对测试用例的描述。
// 每个测试用例的第一行也是唯一一行包含三个整数 n、a和 b（1≤n≤10
// 9
// ，1≤a,b≤n）——分别是网格的格子数，以及每一步中要涂色的格子数。
// 输出
// 对于每个测试用例，如果最终网格的着色可以是对称的，输出 "YES"；否则输出 "NO"。
// 你可以以任意大小写形式输出答案（大写或小写）。例如，字符串 "yEs"、"yes"、"Yes"和 "YES"都会被识别为肯定回答。
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

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	if (b == n) {
		cout <<  "YES" << enl;
		return;
	}
	if (n & 1) {
		if (a >= b && a & 1 && b & 1) { //两个奇数
			cout << "YES" << enl;
		} else if (a < b && b & 1){ //一个奇数，且b比a大
			cout << "YES" << enl;
		} else {
			cout << "NO" << enl;
		}
	} else {
		if (a >= b && a % 2 ==0 && b % 2 == 0) { //两个偶数
			cout << "YES" << enl;
		} else if (a < b && b % 2 == 0){ //b比a大
			cout << "YES" << enl;
		} else {
			cout << "NO" << enl;
		}
	}
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