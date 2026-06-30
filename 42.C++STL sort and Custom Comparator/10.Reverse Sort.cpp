//阿什（Ashish）有一个长度为 n 的二进制字符串 s，他希望将其按非递减顺序排序（即所有 0 在前，1 在后）。
//他可以执行以下操作：
//选择一个子序列，其长度任意，但子序列中的元素必须是非递增的。
//换句话说，选择任意 k（1 ≤ k ≤ n）和任意 k 个下标 1 ≤ i₁ < i₂ < … < iₖ ≤ n，将该子序列原地反转。
//即交换 sᵢ₁ 与 sᵢₖ，交换 sᵢ₂ 与 sᵢₖ₋₁，依此类推，直到完成整个子序列的反转。
//（这里 ⌊x⌋ 表示不超过 x 的最大整数，⌈x⌉ 表示不小于 x 的最小整数。）
//求将字符串按非递减顺序排序所需的最少操作次数。
//可以证明，给定的二进制字符串最多在 n 次操作内一定能被排序。
//输入​
//第一行包含一个整数 t（1 ≤ t ≤ 1000）—— 测试用例的数量。
//每个测试用例的第一行包含一个整数 n（1 ≤ n ≤ 1000）—— 二进制字符串 s 的长度。
//第二行包含一个长度为 n 的二进制字符串 s，仅由 0 和 1 组成。
//保证所有测试用例的 n 之和不超过 1000。
//输出​
//对于每个测试用例，输出如下：
//第一行输出最少操作次数 m（0 ≤ m ≤ n）。
//接下来的 m 行，每行格式为：k i₁ i₂ ... iₖ
//其中 k 是子序列的长度，i₁ < i₂ < ... < iₖ 是所选子序列的下标，且必须满足题目中关于“非递增”的条件。
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
	string s;
	cin >> s;
	int l = 0; int r = n - 1;
	vector<int> ans;
	while (l < r) {
		if (s[l] == '1' && s[r] == '0') {
			ans.push_back(l + 1);
			ans.push_back(r + 1);
			l++;
			r--;
		} 
		if (s[l] == '0') {
			l++;
		}
		if (s[r] == '1') {
			r--;
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.empty()) {
		cout << 0 << enl;
		return;
	}
	cout << 1 << enl;
	cout << ans.size() << ' ';
	if (ans.size() != 0) {
		for (auto i: ans) {
			cout << i << ' ';
		}cout << enl;
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