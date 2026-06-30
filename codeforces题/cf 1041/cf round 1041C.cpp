//阿利和巴哈明决定在伊朗美丽的南部海岸度过他们的暑假。他们还同意在旅途中购买一些东西——但不是设定一个固定预算，而是决定通过玩一个游戏来确定他们将花费多少。
//这个游戏在两个数组 a 和 b 上进行，每个数组包含 n 个整数。
//游戏将进行 k 轮。在一轮中：
//首先，阿利选择两个索引 i 和 j（1 ≤ i < j ≤ n）；
//然后，巴哈明可以任意重新排列四个整数 aᵢ、aⱼ、bᵢ 和 bⱼ。注意，巴哈明可以在两个数组之间交换数字，也可以让两个数组保持不变。
//在所有 k 轮结束后，游戏的值定义为 v = ∑ᵢ₌₁ⁿ |aᵢ − bᵢ|。阿利和巴哈明将正好花费 v 枚硬币。
//然而，他们的目标却大相径庭：
//阿利希望花得尽可能少，即最小化 v；
//巴哈明希望花得尽可能多，即最大化 v。
//你需要找出如果双方都采取最优策略，他们最终会花费多少硬币。
//输入
//每个测试包含多个测试用例。第一行包含测试用例的数量 t（1 ≤ t ≤ 10⁴）。接下来是各测试用例的描述。
//每个测试用例的第一行包含两个整型数 n 和 k（2 ≤ n ≤ 2×10⁵，1 ≤ k ≤ n）——表示数组 a 和 b 的长度，以及轮数。
//第二行包含 n 个整数 a₁, a₂, …, aₙ（1 ≤ aᵢ ≤ 10⁹）——表示数组 a 的元素。
//第三行包含 n 个整数 b₁, b₂, …, bₙ（1 ≤ bᵢ ≤ 10⁹）——表示数组 b 的元素。
//保证所有测试用例的 n 之和不超过 2×10⁵。
//输出
//对于每个测试用例，输出一个整数——表示双方都采取最优策略时，他们最终花费的硬币数量。
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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) cin >>a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	vector<pair<ll, ll>> vec;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll l = min(a[i], b[i]);
		ll r = max(a[i], b[i]);
		vec.push_back({l, r});
		sum += r - l;
	}
	sort(vec.begin(), vec.end());
	ll x = LLONG_MAX;
	ll right = vec[0].second;
	for (int i = 1; i < n; i++) {
		ll left = vec[i].first;
		if (left <= right) { //有重合 玩家A会一直选这个，导致结果不变
			x = 0;
			break;
		} else {
			x = min(x, left - right); //没有重合，他会选最小的相差区间
		}
		right = max(right, vec[i].second); //更新最大的右区间
	}
	if (x == LLONG_MAX) x = 0;
	cout << sum + 2 * x << enl;
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