//你被给定一个数组 a
//如果对于每一对下标 i<j，都满足 i - ai != j - aj 那么称这个数组是 good​ 的。
//你能对这个数组进行洗牌（即任意重排它的元素，保持原顺序也是一种选项）使得它变成 good 吗？
//例如，如果 a=[1,1,3,5]，那么洗牌后的数组[1,3,5,1][3,5,1,1][5,3,1,1]是 good 的，
//而[3,1,5,1][1,1,3,5][1,1,5,3]不是 good 的。
//题目保证：总是存在一种洗牌方式，使数组满足条件。
//输入​
//第一行包含一个整数 t（1≤t≤100）—— 测试用例的数量。
//每个测试用例的第一行包含一个整数 n（1≤n≤100）—— 数组 a的长度。
//第二行包含 n个整数 a
//输出​
//对于每个测试用例，输出一个洗牌后的数组 a的版本，使其是 good 的。
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
	sort(arr.begin(), arr.end(), greater<int>()); //就是一个倒序输出
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	} cout << enl;
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