//套娃是一种木制玩具，外形像是一个彩绘的娃娃，里面可以放一个尺寸更小的类似娃娃。
//一套嵌套娃娃由一或多个嵌套娃娃组成，它们的尺寸是连续的正整数。因此，一套嵌套娃娃可以用两个数字来描述：s——该套中最小娃娃的尺寸，m——该套中娃娃的数量。换句话说，这套娃娃包含尺寸为 s, s+1, …, s+m−1 的娃娃，其中 s, m 是正整数。
//你原本有一套或多套嵌套娃娃。最近你发现有人把你的所有套娃混在了一起，并记录下了一个娃娃尺寸序列——整数 a₁, a₂, …, aₙ。
//你已经不记得原来有多少套了，所以你想求出最初可能有的最少套数。
//例如，如果给定的序列是 a = [2, 2, 3, 4, 3, 1]。最初可能有 2 套：
//第一套由 4 个嵌套娃娃组成，尺寸为 [1, 2, 3, 4]；
//第二套由 2 个嵌套娃娃组成，尺寸为 [2, 3]。
//根据给定的一系列嵌套娃娃尺寸 a₁, a₂, …, aₙ，确定能组成该序列的最小套数。
//每套必须被完全使用，即其中的所有嵌套娃娃都要被用到。给定序列中的每个元素必须恰好对应某套中的一个娃娃。
//输入​
//第一行输入一个整数 t（1 ≤ t ≤ 10⁴）—— 测试用例的数量。
//接下来是各测试用例的描述。
//每个测试用例的第一行包含一个整数 n（1 ≤ n ≤ 2×10⁵）—— 所有套娃中的总数量。
//每个测试用例的第二行包含 n 个整数 a₁, a₂, …, aₙ（1 ≤ aᵢ ≤ 10⁹）—— 各套娃的尺寸。
//保证所有测试用例的 n 之和不超过 2×10⁵。
//输出​
//对于每个测试用例，输出一个整数 k——可能的最少套数。
#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <cmath>
#include <unordered_set>

using namespace std;
using ll = long long;
using vi = vector<int>;
const char enl = '\n';

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	map<ll, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a.rbegin(), a.rend());
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!mp[a[i]]) continue;
		ll x = a[i];
		mp[x]--;
		while (1) {
			if (mp[x - 1] > 0) {
				mp[x - 1]--;
				x -= 1;
			} else {
				break;
			}
		}
		cnt++;
	}
	cout << cnt << enl;
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