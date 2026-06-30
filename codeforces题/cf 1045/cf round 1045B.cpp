// 给定一个包含 n 个正整数 a1, a2, …, an 的数组，以及一个正整数 k。
// 在一次操作中，你可以给每个 ai 加上 0 或 k，即选择另一个由 n 个整数 b1, b2, …, bn 组成的数组，其中每个 bi 要么是 0，要么是 k，然后对于所有 1 ≤ i ≤ n，将 ai 更新为 ai + bi。注意，对于数组 b 的每个元素，你可以选择不同的值。
// 你的任务是最多执行 k 次这样的操作，使得 gcd(a1, a2, …, an) > 1。可以保证这总是可行的。
// 输出操作完成后的最终数组。你不需要输出具体的操作步骤。
// 这里 gcd(a1, a2, …, an) 表示 a1, a2, …, an 的最大公约数。
// 输入
// 每个测试包含多组测试用例。第一行包含测试用例的数量 t（1 ≤ t ≤ 1000）。接下来是对测试用例的描述。
// 每个测试用例的第一行包含两个整数 n 和 k（1 ≤ n ≤ 10^5，1 ≤ k ≤ 10^9）——数组 a 的长度和给定的常数。
// 每个测试用例的第二行包含 n 个整数 a1, a2, …, an（1 ≤ ai ≤ 10^9）——数组 a 的元素。
// 保证所有测试用例中 n 的总和不超过 10^5。
// 输出
// 对于每个测试用例，在新的一行输出 n 个整数——操作完成后的最终数组。输出中的整数应在 1 到 10^9 + k^2 范围内。
// 如果有多个有效输出，你可以输出任意一个。
// 注意：你不需要最小化操作次数。
#include <iostream>
#include <vector>
#include <numeric>
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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (k & 1) {
		for (int i = 0; i < n; i++) {
			if (a[i] & 1) {
				a[i] += k;
			}
		}
	} else {
		for (int i = 0; i < n; i++) {  //a + a * k = a * (k + 1); k+1的倍数 还要取余k + 1使得操作数在0 到 k之间
			a[i] = (a[i] + a[i] % (k + 1) * k);
		}
	}
	for (auto& i: a) {
		cout << i << ' ';
	}cout << enl;
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