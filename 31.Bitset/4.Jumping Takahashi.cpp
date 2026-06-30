//高桥站在一个数轴的原点 0 处。
//他现在要进行 N 次跳跃。在第 i 次跳跃 (1 ≤ i ≤ N) 中，他会向正方向移动 aᵢ 或 bᵢ 的距离。
//问：经过 N 次跳跃后，他能否到达坐标 X？
//约束条件​
//1 ≤ N ≤ 100
//1 ≤ ai < bi ≤ 100 (1 ≤ i ≤ N)
//1 ≤ X ≤ 10000
//输入的所有值都是整数。
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
const char enl = '\n';

void solve() {
	int n, x;
	cin >> n >> x;
	bitset<10001> bs;
	bs[0] = 1;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		bitset<10001> t;
		t |= (bs << a);
		t |= (bs << b);
		bs = t;
	}
	if (bs[x]) {
		cout << "Yes" << enl;
	} else {
		cout << "No" << enl;
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