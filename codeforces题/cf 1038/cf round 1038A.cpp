//在一个网格中，一条路径被称为“贪心路径”
//如果它从左上角的单元格出发，每一步只能向右或向下移动，并且每次总是移动到相邻的值更大的单元格（如果相等则任选其一）。
//一条路径的价值是它经过的所有单元格的值之和，包括起点和终点。
//是否存在一个 n×m 的非负整数网格，使得没有任何一条贪心路径能够取得所有向下/向右路径中的最大价值？
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

void solve () {
	int n, m;
	cin >> n >>m;
	if (n == 1 || m == 1) {
		cout << "NO" << enl;
		return;
	} 
	if (n >= 3 || m >= 3) {
		cout << "YES" << enl;
	} else {
		cout << "NO" << enl;
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