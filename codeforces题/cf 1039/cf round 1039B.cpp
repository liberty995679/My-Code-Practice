//我们称一个大小为 n 的数组 a 是“坏的”，当且仅当存在 1≤i≤n−4，使得以下条件之一成立：
//ai < ai+1 < ai+2 < ai+3 < ai+4
//ai > ai+1 > ai+2 > ai+3 > ai+4
//一个数组如果不是坏的，就被称为“好的”。例如：
//a = [3,1,2,4,5,6] 是坏的，因为 a2 < a3 < a4 < a5 < a6。
//a = [7,6,5,4,1,2,3] 是坏的，因为 a1 > a2 > a3 > a4 > a5。
//a = [7,6,5,1,2,3,4] 是好的。
//给定一个排列∗ p1,p2,…,pn。
//你需要进行 n 轮操作。在每一轮中，你必须删除当前 p 中最左边或最右边的元素。令 qi 表示第 i 轮删除的元素。
//请在每一轮中选择要删除的元素，使得最终得到的数组 q 是好的。我们可以证明，在给定的约束条件下，总是可行的。
//∗ 长度为 n 的排列是指一个由 1 到 n 的 n 个不同整数按任意顺序排列组成的数组。例如，[2,3,1,5,4] 是一个排列，但 [1,2,2] 不是排列（2 出现了两次），[1,3,4] 也不是排列（n=3 但数组中出现了 4）。
//输入
//每个测试包含多组测试用例。第一行包含测试用例的数量 t (1≤t≤10000)。接下来是对测试用例的描述。
//每个测试用例的第一行包含一个整数 n (5≤n≤100000) —— 数组的长度。
//每个测试用例的第二行包含 n 个整数 p1,p2,…,pn (1≤pi≤n，pi 两两不同) —— 表示排列中的元素。
//保证所有测试用例中 n 的总和不超过 200000。
//输出
//对于每个测试用例，输出一个长度为 n 的字符串 s。对于每一个 1≤i≤n，在第 i 轮：
//si = 'L' 表示删除了 p 的最左边的元素
//si = 'R' 表示删除了 p 的最右边的元素
//我们可以证明答案总是存在的。如果有多种解，输出任意一个即可。
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
	int l = 0; int r = n - 1;
	for (int i = 1; i <= n / 2; i++) {
		if (i & 1) { //奇数轮先删除小的
			if (arr[l] > arr[r]) {
				cout << "RL";
			} else {
				cout << "LR";
			} 
		}else { //偶数轮删除大的
			if (arr[l] > arr[r]) {
				cout << "LR";
			} else {
				cout << "RL";
			}
		}l++; r--;
	}
	if (n % 2 == 1) { //如果是奇数n 再删除一个即可
      cout << "L";
    }
	cout << enl;
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
