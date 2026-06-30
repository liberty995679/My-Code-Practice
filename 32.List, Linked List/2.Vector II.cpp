//给定 n 个动态数组 A₀, A₁, ..., Aₙ₋₁，执行以下操作：
//pushBack(t, x)：将元素 x 添加到数组 Aₜ 的末尾。
//dump(t)：打印数组 Aₜ 中的所有元素。
//clear(t)：清空数组 Aₜ。如果 Aₜ 已经为空，则不执行任何操作。
//每个数组 Aᵢ 索引从 0 开始，初始为空。
//输入​
//输入格式如下：
//n q
//query₁
//query₂
//…
//query_q
//每个查询 queryᵢ 的形式为：
//0 t x：表示 pushBack(t, x) 操作
//1 t：表示 dump(t) 操作
//2 t：表示 clear(t) 操作
//其中第一个数字 0、1、2 分别表示 pushBack、dump 和 clear 操作。
//输出​
//对于每个 dump 操作，在一行中输出数组 Aₜ 的所有元素，相邻元素之间用一个空格分隔（最后一个元素后不输出空格）。如果数组为空，则输出一个空行。
#include <iostream>
#include <algorithm>
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
const char enl = '\n';

void solve() {
	int n, q;
	cin >> n >> q;
	vector<list<int>> nums(n);
	for (int i = 0; i < q; i++) {
		int m, t, x;
		cin >> m >> t;
		if (m == 0) {
			cin >> x;
			nums[t].push_back(x);
		} else if (m == 1) {
			if (!nums[t].empty()) {
				bool flag = true;
				for (auto it: nums[t]) {
					if (!flag) cout << ' ';
					cout << it;
					flag = false;
				}
			}cout << enl;  //数组为空打印空行
		} else {
			nums[t].clear();
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}