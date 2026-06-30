///对于一个由非负整数构成的多重集 T，我们定义：
//sum(T)​ 是 T 中所有元素的和。例如，如果 T = {0, 1, 1, 3}，那么 sum(T) = 0 + 1 + 1 + 3 = 5。
//mex(T)​ 是不在 T 中的最小非负整数。例如，如果 T = {0, 1, 1, 3}，那么 mex(T) = 2，因为 2 是不在 T 中的最小非负整数。
//给定一个包含 n 个非负整数的多重集 S。初始时，你的得分为 0。你可以按任意顺序执行以下操作任意次数（也可以不执行）：
//选择一个子集 S′ ⊆ S（即 S′ 包含 S 中当前的一些元素），将 sum(S′) 加到你的得分中，然后从 S 中移除 S′。
//选择一个子集 S′ ⊆ S，将 mex(S′) 加到你的得分中，然后从 S 中移除 S′。
//求可以获得的最大可能得分。
//输入
//每个测试包含多组测试用例。第一行包含测试用例的数量 t (1 ≤ t ≤ 10³)。接下来是测试用例的描述。
//每个测试用例的第一行包含一个整数 n (1 ≤ n ≤ 50)。
//每个测试用例的第二行包含 n 个整数 S₁, S₂, …, Sₙ (0 ≤ Sᵢ ≤ 50)。
//输出
//对于每个测试用例，打印一个整数——可以获得的最大可能得分。
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
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) cnt++;
		sum += arr[i];
	}
	cout << sum + cnt << enl;
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
