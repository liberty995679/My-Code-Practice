// 如果一个数组的每一个长度至少为 2 的子数组都满足：其中位于原数组中偶数下标上的元素之和，大于等于位于奇数下标上的元素之和，那么这个数组被称为“好”数组。数组下标从 1 开始。
// 例如，数组 [3,8,4,4] 和 [2,3,1,4,2] 是好数组。数组 [0,2,4,1] 不是好数组，因为在子数组 [2,4,1] 中，在原数组中处于偶数下标上的元素是 2（下标 2）和 1（下标 4），而处于奇数下标上的唯一元素是 4（下标 3）。由于 2+1 < 4，这个条件在该子数组上不成立。
// 给定一个包含 n 个非负整数 a1, a2, …, an 的数组。在一次操作中，你可以将数组中的任意元素减少 1，但所有元素必须保持非负。你的任务是找出使数组 a 变为好数组所需的最少操作次数。可以保证，使用有限次操作一定能使数组变好。
// 这里，如果数组 b 可以通过删除数组 a 开头若干个（可以是零个或全部）元素以及结尾若干个（可以是零个或全部）元素得到，则数组 b 是数组 a 的子数组。
// 输入
// 每个测试包含多组测试用例。第一行包含测试用例的数量 t（1 ≤ t ≤ 10^4）。接下来是对测试用例的描述。
// 每个测试用例的第一行包含一个整数 n（2 ≤ n ≤ 2×10^5）——数组 a 的长度。
// 每个测试用例的第二行包含 n 个非负整数 a1, a2, …, an（0 ≤ ai ≤ 10^9）——数组 a 的元素。
// 保证所有测试用例中 n 的总和不超过 2×10^5。
// 输出
// 对于每个测试用例，在新的一行输出一个整数——使数组 a 变为好数组所需的最少操作次数。
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
	int n;
	cin >> n;
	vector<ll> arr(n + 2);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		ll sum;
		if (n > 2) {
			if (i % 2 == 0) {
				if (arr[i - 1] > arr[i]) {
					ans += arr[i - 1] - arr[i];
					arr[i - 1] = arr[i];
				}
				if (arr[i + 1] > arr[i]) {
					ans += arr[i + 1] - arr[i];
					arr[i + 1] = arr[i];
				}
				sum = arr[i - 1] + arr[i + 1];
				if (sum > arr[i]) {
					ans += sum - arr[i];
					arr[i + 1] -= (sum - arr[i]);
				}
			}
		}
		else {
			sum = arr[i - 1];
			if (i % 2 == 0) {
				if (sum > arr[i]) {
					ans += sum - arr[i];
				}
			}
		}
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