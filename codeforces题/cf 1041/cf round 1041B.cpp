//Mani 把 Hamid 关在一个 1×n的网格里。一开始，网格的某些格子有墙，其余是空的，Hamid 位于一个空格子中。
//每一天，按以下顺序发生事件：
//Mani 选择一个空格子，并在该格建一堵墙。注意，他不能在 Hamid 当前所在的格子建墙；
//Hamid 选择一个方向（左或右），然后：
//如果该方向没有墙，他就逃出网格；
//否则，他会移动到该方向上最近的一堵墙，并摧毁这堵墙。摧毁后，Hamid 会站在这堵墙的位置。
//以下是一个 n=6时可能行动序列的例子：
//Hamid 始终知道墙的位置。他想最小化自己逃出网格所需的天数，而 Mani 想最大化这个天数。
//你需要确定在双方都采取最优策略的情况下，Hamid 需要多少天才能逃出网格。
//输入
//每个测试包含多个测试用例。第一行包含测试用例数量 t（1≤t≤104
//）。每个测试用例描述如下：
//第一行两个整数 n和 x（2≤n≤2⋅10
//，1≤x≤n）——网格的大小，以及 Hamid 的初始位置。他初始时在第 x个格子（从左往右数）。
//第二行一个长度为 n的字符串 s（s_i = \text{`#`}或 .）——网格的初始状态。第 i个格子有墙当且仅当 s_i = \text{`#`}，否则为空。
//保证第 x个格子是空的，且网格中至少有两个空格子。
//保证所有测试用例的 n之和不超过 2⋅10
//对于每个测试用例，输出一个整数——在双方都采取最优策略时，Hamid 逃出网格需要的天数。
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
	int n, x;
	cin >> n >> x;
	string s;
	cin >> s;
	int pos = x - 1;
	 // 在边界，直接1天
    if (x == 1 || x == n) {
        cout << 1 << enl;
        return;
    }
	int inf = 1e9;  // 关键：用无穷大而不是-1
    int L_idx = -inf;  // 左边没墙时用负无穷
    int R_idx = inf;   // 右边没墙时用正无穷
	for (int i = pos - 1; i >= 0; i--) {
		if (s[i] == '#') {
			L_idx = i;
			break;
		}
	}
	for (int i = pos + 1; i < n; i++) {
		if (s[i] == '#')  {
			R_idx = i;
			break;
		}
	}
 	// 两边都没墙 - 直接一天逃出
    if (L_idx == -inf && R_idx == inf) {
        cout << 1 << enl;
        return;
    }
	int l = L_idx;
    int r = R_idx;
    int ans = max(min(pos + 1, n - r + 1), min(l + 2, n - pos));  //尝试向左逃，尝试向右逃
	cout << ans << enl;
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