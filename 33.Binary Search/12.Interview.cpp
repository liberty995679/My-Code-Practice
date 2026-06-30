// 这是一个交互题。​ 如果你不确定交互题是如何运作的，建议阅读参赛者指南。
// 在考试的最后阶段之前，导演进行了一次面试。他给了 Gon n​ 堆石子，第 i​ 堆有 a_i​ 个石子。
// 每个石子都是相同的，重 1 克，除了某一堆中包含一个特殊的石子，它重 2 克。
// [图示：第一个测试用例。第 2 堆含有特殊石子。各堆重量分别为 1, 3, 3, 4, 5。]
// Gon 只能向导演提出一种类型的问题：他可以选择 k​ 堆，导演会告诉他所选堆的总重量。更正式地说，Gon 可以选择一个整数 k（1 ≤ k ≤ n）以及 k​ 个不同的堆编号 p_1, p_2, …, p_k（1 ≤ p_i ≤ n），导演将返回这些堆的总重量 m{p_1} + m{p_2} + ⋯ + m_{p_k}，其中 m_i​ 表示第 i​ 堆的重量。
// Gon 的任务是找出包含特殊石子的那一堆。然而，导演很忙。请帮助 Gon 在最多 30 次查询内找到这堆石子。
// 输入
// 输入数据包含多个测试用例。第一行包含一个整数 t（1 ≤ t ≤ 1000）—— 测试用例的数量。接下来是各个测试用例的描述。
// 每个测试用例的第一行包含一个整数 n（1 ≤ n ≤ 2·10⁵）—— 堆的数量。
// 第二行包含 n​ 个整数 a_i（1 ≤ a_i ≤ 10⁴）—— 每堆的石子数量。
// 保证所有测试用例中 n​ 的总和不超过 2·10⁵。
// 读取完每个测试用例的输入后，请按如下方式进行交互。
// 交互说明
// 你可以在最多 30 次操作内猜测目标堆。
// 要进行一次猜测，请打印一行，格式如下：
// ? k p1 p2 p3 ... pk
// （1 ≤ k ≤ n；1 ≤ p_i ≤ n；所有 p_i 互不相同）—— 所选堆的编号。
// 每次操作后，你需要读入一行，包含一个整数 x​ —— 所选堆的重量之和。（正式地，x = m{p_1} + m{p_2} + ⋯ + m_{p_k}。）
// 当你确定包含特殊石子的堆的编号后，请打印一行，格式如下：
// ! m
// （1 ≤ m ≤ n）。
// 随后进入下一个测试用例，如果没有更多测试用例则结束程序。
// 如果你的程序在一个测试用例中执行了超过 30 次操作，或提出了非法查询，你可能会收到 Wrong Answer​ 的结果。
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

void solve(){
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	vector<int> pre(n + 2);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + arr[i];
	}
	int l = 1; int  r = n;
	while (l < r) {
		int mid = (r + l) / 2;
		int len = mid - l + 1;
		cout << "? " << len << ' ';
		for (int i = l; i <= mid; i++) {
			cout << i << ' ';
		}cout << endl;
		int res;
		cin >> res;
		if (pre[mid] - pre[l - 1] != res) {
			r = mid;
		} else{
			l = mid + 1;
		}
		cout << endl;
	}
	cout << "! " << r << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}