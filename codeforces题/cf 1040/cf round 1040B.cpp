//有一个由数值 0、1 和 2 组成的数组 a1, a2, …, an，以及一个整数 s。保证数组 a1, a2, …, an 至少包含一个 0、一个 1 和一个 2。
//Alice 想要从下标 1 开始，执行向右或向左长度为 1 的步长，最终到达下标 n。
//在 Alice 移动的过程中，她会计算她所访问位置的值的总和，并且她希望这个总和恰好等于 s。
//形式上，Alice 想要找到一个索引序列 [i1, i2, …, im]，满足：
//1 = 1，im = n。
//对于所有 1 ≤ j ≤ m，有 1 ≤ ij ≤ n。
//对于所有 1 ≤ j < m，有 |ij − ij+1| = 1。
//ai1 + ai2 + … + aim = s。
//然而，Bob 想要重新排列 a1, a2, …, an 以防止 Alice 实现她的目标。请判断是否可以重新排列 a1, a2, …, an，使得 Alice 找不到她的目标序列（即使 Alice 足够聪明）。如果可能，你还需要输出重新排列后的数组 a1, a2, …, an。
//输入
//每个测试包含多组测试用例。第一行包含测试用例的数量 t (1 ≤ t ≤ 10^3)。接下来是测试用例的描述。
//每个测试用例的第一行包含两个整数 n 和 s (3 ≤ n ≤ 50, 0 ≤ s ≤ 1000)。
//每个测试用例的第二行包含 n 个整数 a1, a2, …, an (0 ≤ ai ≤ 2)。
//保证 a 至少包含一个 0、一个 1 和一个 2。
//输出
//对于每个测试用例，如果可以重新排列 a 使得 Alice 找不到她的目标序列，则输出 n 个整数——即 a 的一种重新排列。否则，请输出 -1。
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
	int sum = 0;
	int n, s;
	cin >> n >> s;
	vector<int> arr(n);
	int cnt0 = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 0) cnt0++;
		else if (arr[i] == 1) cnt1++;
		else cnt2++;
		sum += arr[i];
	}
	if (sum > s) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}cout << enl;
		return;
	} 
	if (sum == s) {
		cout << -1 << enl;
		return;
	}
	if (s - sum == 1) {  //如果相差1 就需要避开01这种，以免一直刷,所以是0 2 1
		for (int i = 0; i < cnt0; i++) cout << 0 << ' ';
		for (int i = 0; i < cnt2; i++) cout << 2 << ' ';
		for (int i = 0; i < cnt1; i++) cout << 1 << ' ';
		cout << enl;
	} else {
		cout << -1 << enl;  //差值大于1，则01 02 12 21这种情况都有1 2 3奇数偶数都包含了，总有可能成功
	}
	
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
