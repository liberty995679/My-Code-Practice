//你有一个长度为 n 的整数数组 a。可以对这个数组执行以下操作：
//交换两个元素 aᵢ 和 aⱼ，要求 i ≠ j，并且 aᵢ 和 aⱼ 要么都是偶数，要么都是奇数。
//请判断：能否通过执行该操作任意次（可能为零次），使数组按非递减顺序排序。
//例如，设 a = [7, 10, 1, 3, 2]。我们可以执行 3 次操作来排序数组：
//交换 a₃ = 1 和 a₁ = 7，因为 1 和 7 都是奇数。得到 a = [1, 10, 7, 3, 2]；
//交换 a₂ = 10 和 a₅ = 2，因为 10 和 2 都是偶数。得到 a = [1, 2, 7, 3, 10]；
//交换 a₄ = 3 和 a₃ = 7，因为 3 和 7 都是奇数。得到 a = [1, 2, 3, 7, 10]。
//输入​
//输入数据的第一行包含一个整数 t（1 ≤ t ≤ 10⁴）—— 测试用例的数量。
//每个测试用例的描述如下：
//第一行包含一个整数 n（1 ≤ n ≤ 2·10⁵）—— 数组 a 的长度。
//第二行包含 n 个正整数 a₁, a₂, …, aₙ（1 ≤ aᵢ ≤ 10⁹）—— 数组 a 的元素。
//保证所有测试用例的 n 之和不超过 2·10⁵。
//输出​
//对于每个测试用例，单独输出一行：
//如果可以通过若干次操作使数组排序，输出 YES；
//否则输出 NO。
//大小写不敏感，例如 yEs、yes、Yes 和 YES 都会被识别为肯定回答。
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
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<int> b = arr;
	sort(b.begin(), b.end());
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != b[i] % 2) {
			flag = false;
			break;
		}
	}
	if (flag) cout << "YES" << enl;
	else cout << "NO" << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
    return 0;
}