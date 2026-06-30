//考虑一个数组 a1,…,an。
//初始时，对所有 i，都有 ai = 0。
//你可以执行如下形式的操作：
//选择一个大于 min(a) 的整数 x。
//然后，定义 i 为满足 ai < x 的最小下标。换句话说，i 是介于 1 到 n（含）之间的唯一整数，使得 ai < x，且对于所有 1 ≤ j ≤ i−1，都有 aj ≥ x。
//最后，将 ai 增加 x。
//例如，若 a = [6,8,2,1]，你选择 x = 6，那么 i 将等于 3（因为 a1 ≥ 6，a2 ≥ 6，而 a3 < 6），之后 a 变为 [6,8,8,1]。
//你可以执行任意多次操作。请问能否得到目标数组 b1,…,bn？
//输入
//每个测试包含多组测试用例。第一行包含测试用例的数量 t (1≤t≤10000)。接下来是对测试用例的描述。
//每个测试用例的第一行包含一个整数 n (2≤n≤200000)。
//每个测试用例的第二行包含 n 个整数 b1,b2,…,bn (1≤bi≤10^9)。
//所有测试用例中 n 的总和不超过 200000。
//输出
//对于每个测试用例，如果可以得到目标数组，输出 YES，否则输出 NO。
//你可以以任意大小写形式输出答案（大写或小写）。例如，字符串 "yEs"、"yes"、"Yes" 和 "YES" 都会被识别为肯定回答。
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
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (i == 0) mn = arr[i]; 
		else {
			if (arr[i] >= 2 * mn) {  //因为a[i]能取前面min(a[j]) 所以原来的a[i] 最大取x - 1(a[i] < x, a[j] >= x)
				cout << "NO" << enl;   //现在的a[i]则是 x - 1 + x == 2x - 1(最大能取到)
				return;
			}
			mn = min(mn, arr[i]);
		}
	}
	cout << "YES" << enl;
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
