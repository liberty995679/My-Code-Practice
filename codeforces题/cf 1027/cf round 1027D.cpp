//游戏场地是一个大小为 10 的 9 次方 乘 10 的 9 次方 的矩阵，第 a 行与第 b 列交叉处的单元格记为 (a, b)。
//场上有 n 只怪物，第 i 只怪物位于单元格 (x[i], y[i])，其余单元格为空。每个单元格最多只能有一只怪物。
//你最多可以将一只怪物移动到场上任意一个未被其他怪物占据的单元格，且这种移动最多执行一次。
//之后，你必须选择场上的一个矩形；该矩形内的所有怪物都会被消灭。你必须为所选矩形内的每个单元格支付 1 枚金币。
//你的任务是找到消灭所有 n 只怪物所需的最少金币数。
//输入格式​
//第一行包含一个整数 t（1 小于等于 t 小于等于 10 的 4 次方）—— 测试用例数量。
//每个测试用例的第一行包含一个整数 n（1 小于等于 n 小于等于 2 乘 10 的 5 次方）—— 场上怪物的数量。
//接下来的 n 行，每行包含两个整数 x[i] 和 y[i]（1 小于等于 x[i], y[i] 小于等于 10 的 9 次方）—— 第 i 只怪物的坐标。所有 (x[i], y[i]) 两两不同。
//保证所有测试用例的 n 之和不超过 2 乘 10 的 5 次方。
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
	ll n;
	cin >> n;
	multiset<ll> a, b;
	vector<ll> x(n), y(n);
	for (int i = 0 ; i < n; i++) {
		cin >> x[i] >> y[i];
		a.insert(x[i]);
		b.insert(y[i]);		
	}
	ll wight = *a.rbegin() - *a.begin() + 1;
	ll high = *b.rbegin() - *b.begin() + 1;
	ll ans = wight * high; //原本的大小
	for (int i = 0; i < n; i++) { 
		a.erase(a.find(x[i]));
		b.erase(b.find(y[i]));  //先删除这个点
		if (a.empty() || b.empty()) {
			a.insert(x[i]);
			b.insert(y[i]);
			continue;
		}
		ll w = *a.rbegin() - *a.begin() + 1;
		ll h = *b.rbegin() - *b.begin() + 1;
		ans = min(ans, w * h);
		if (ans == n - 1) {  //如果格子已经满了 , 删了一个，剩下的数刚好满格子
			ans += min(w, h); //所以删掉的那个数放在更小的行列里
		}
		a.insert(x[i]);  //添加回去
		b.insert(y[i]);
	}
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