//Iulia 有 n 个玻璃杯排成一行。第 i 个玻璃杯中有 aᵢ 单位的果汁。
//Iulia 只喝奇数编号的玻璃杯里的果汁，而她的约会对象只喝偶数编号的玻璃杯里的果汁。
//为了给她的约会对象留下好印象，Iulia 想找到一个连续的玻璃杯子数组，
//使得只考虑这个子数组时，她和她的约会对象喝到的果汁总量相等。请帮她找到这样的子数组。
//更正式地说，判断是否存在两个下标 l, r，满足 1 ≤ l ≤ r ≤ n，并且：
//如果 l 和 r 奇偶性相同，则 aₗ + aₗ₊₂ + aₗ₊₄ + … + aᵣ = aₗ₊₁ + aₗ₊₃ + … + aᵣ₋₁；
//如果 l 和 r 奇偶性不同，则 aₗ + aₗ₊₂ + aₗ₊₄ + … + aᵣ₋₁ = aₗ₊₁ + aₗ₊₃ + … + aᵣ。
//输入​
//第一行包含一个整数 t（1 ≤ t ≤ 10⁴）—— 测试用例的数量。
//每个测试用例的第一行包含一个整数 n（1 ≤ n ≤ 2×10⁵）—— 玻璃杯的总数。
//每个测试用例的第二行包含 n 个整数 a₁, …, aₙ（1 ≤ aᵢ ≤ 10⁹）—— 每个玻璃杯中的果汁量。
//所有测试用例的 n 之和不超过 2×10⁵。
//输出​
//对于每个测试用例，如果存在满足条件的连续子数组，输出 "YES"，否则输出 "NO"。
//答案可以用任意大小写形式输出（例如，"yEs"、"yes"、"Yes" 和 "YES" 都会被识别为肯定答案）。
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
    set<ll> st;
    ll sum1 = 0; 
	ll sum2 = 0;
    st.insert(0);
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		ll x = a[i];
		if (i & 1) {
			sum1 += x;
		} else {
			sum2 += x;
		}
		ll cur = sum1 - sum2;  
		if (st.count(cur)) {  //sum1[r] - sum2[r] == sum1[l] - sum2[l]
			cout << "YES" << enl;
			return;
		}
		st.insert(cur);
	}
	cout << "NO" << enl;
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