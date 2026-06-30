//Mishka 有 n 个空盒子。对于每个 i（1 ≤ i ≤ n），第 i 个盒子是一个边长为 aᵢ 的立方体。
//Mishka 可以将一个盒子 i 放入另一个盒子 j 中，当且仅当满足以下条件：
//第 i 个盒子没有被放入其他盒子中；
//第 j 个盒子中不包含任何其他盒子；
//盒子 i 比盒子 j 小（aᵢ < aⱼ）。
//Mishka 可以任意次数地将盒子套入其他盒子。他希望最小化可见盒子的数量。一个盒子被称为可见，当且仅当它没有被放入另一个盒子中。
//请帮助 Mishka 确定可见盒子的最小可能数量！
//输入​
//第一行包含一个整数 n（1 ≤ n ≤ 5000）—— Mishka 拥有的盒子数量。
//第二行包含 n 个整数 a₁, a₂, ..., aₙ（1 ≤ aᵢ ≤ 10⁹），其中 aᵢ 是第 i 个盒子的边长。
//输出​
//输出可见盒子的最小可能数量。
#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;
using vi = vector<int>;
const char enl = '\n';

void solve() {
	map<int, int> mp;
	int n;
	cin >> n;
	vi a(n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
		mx = max(mp[a[i]], mx);
	}
	cout << mx << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}