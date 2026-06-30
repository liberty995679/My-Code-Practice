//有 N 个物品，编号为 1, 2, …, N。对于每个 i（1 ≤ i ≤ N），第 i 个物品的权重为 w_i，价值为 v_i。
//太郎决定从这 N 个物品中选择若干个，放入背包带回家。背包的容量为 W，这意味着所选物品的总重量不能超过 W。
//求太郎带回家的物品价值之和的最大值。
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
	int n, w;
	cin >> n >> w;
	vector<ll> W(n), v(n); 
	for (int i = 0; i < n; i++) cin >> W[i] >> v[i];
	vector<ll> dp(w + 1);
	for (int i = 0; i <n; i++) {
		for (int j = w; j >= W[i]; j--) {
			dp[j] = max(dp[j], dp[j - W[i]] + v[i]);  //01背包问题
		}
	}
	cout << dp[w] << enl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
    return 0;
}