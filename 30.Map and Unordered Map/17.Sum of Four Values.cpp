//你被给定一个由 n 个整数组成的数组，你的任务是找到四个不同位置上的值，使它们的和等于 x。
//输入​
//第一行有两个整数 n 和 x：表示数组的大小和目标总和。
//第二行有 n 个整数 a₁, a₂, …, aₙ：表示数组的值。
//输出​
//输出四个整数：表示满足条件的四个值的位置。
//如果有多个解，你可以输出任意一个。如果无解，则输出 IMPOSSIBLE。
#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;
using ll = long long;
using vi = vector<int>;
const char enl = '\n';

void solve() {
	map<ll, pair<ll,ll>> mp;
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll need = x - a[i] - a[j]				;
			if (mp.count(need)) {
				int p = mp[need].first; int q = mp[need].second;
				if (p != q && p != i && p != j && q != i && q != j) {
					cout << i << ' ' << j << ' ' << p << ' ' << q << enl;
					return;
				}
			}
		}
		for (int k = 1; k < i; k++) {
			mp[a[k] + a[i]] = {k, i};
		}
	}
	cout << "IMPOSSIBLE" << enl;
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