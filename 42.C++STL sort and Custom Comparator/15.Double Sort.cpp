//你有两个数组 a 和 b，每个都包含 n 个整数。
//你可以执行一次“顺滑”操作：选择两个下标 i 和 j（1 ≤ i, j ≤ n；i ≠ j），并同时交换这两个位置上的元素——也就是说，在 a 中交换 a[i] 和 a[j]，在 b 中交换 b[i] 和 b[j]。
//你最多可以进行 10⁴ 次这样的操作（也可以不操作）。最终，能否让两个数组都按非递减顺序排序？如果可以，请展示任意一组能实现目标的交换序列。
//输入​
//第一行给出一个整数 t（1 ≤ t ≤ 100）——测试用例的数量。
//对于每个测试用例，第一行有一个整数 n（2 ≤ n ≤ 100）——两个数组的大小。
//下一行列出 n 个整数 a₁, a₂, …, aₙ（1 ≤ aᵢ ≤ n）——第一个数组。
//再下一行有 n 个整数 b₁, b₂, …, bₙ（1 ≤ bᵢ ≤ n）——第二个数组。
//输出​
//对于每个测试用例，输出你的答案。如果在 10⁴ 次操作内无法将两个数组都按非递减顺序排序，则只输出 -1。否则，先输出操作次数 k（0 ≤ k ≤ 10⁴），然后对于每次操作，输出你交换的两个下标 i 和 j（1 ≤ i, j ≤ n；i ≠ j）。
//如果有多种解决方案，可以输出其中任意一种。不需要最小化操作次数。
#include <iostream>
#include <algorithm>
#include <sstream>
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
using ll = long long;
const char enl = '\n';

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1] || b[j] > b[j + 1]) { //因为a如果有序，b是逆序也要交换
				swap(a[j], a[j + 1]);
				swap(b[j], b[j + 1]);
				ans.push_back({j, j + 1});
			}
		}
	}  //最后判断两个是否都有序
	if (is_sorted(b.begin(), b.end()) && is_sorted(a.begin(), a.end())){ 
		cout << ans.size() << enl;
		for (auto it : ans) {
			cout << it.first + 1 << ' ' << it.second + 1 << enl;
		}
	} else {
		cout << -1 << enl;
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) solve();
    return 0;
}