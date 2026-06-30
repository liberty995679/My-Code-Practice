#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
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
string s = " ";

struct Node {
    long long cnt, sum; // 个数、数位和
};

Node dp[20][2];
bool vis[20][2];
vector<int> dig;
// 数位DP：返回从当前位到末尾的 {数量, 数位和}
Node dfs(int pos, bool tight) {
    if (pos == dig.size()) return {1, 0};
    if (vis[pos][tight]) return dp[pos][tight];

    int up = tight ? dig[pos] : 9;
    Node res = {0, 0};

    for (int d = 0; d <= up; d++) {
        Node nxt = dfs(pos + 1, tight && (d == up));
        res.cnt += nxt.cnt;
        res.sum += nxt.sum + nxt.cnt * d;
    }

    vis[pos][tight] = 1;
    return dp[pos][tight] = res;
}

// 求 1 ~ x 的数位和
ll calc(ll x) {
    if (x <= 0) return 0;
    dig.clear();
    while (x) {
        dig.push_back(x % 10);
        x /= 10;
    }
    reverse(dig.begin(), dig.end());

    memset(vis, 0, sizeof(vis));
    return dfs(0, 1).sum;
}

void solve() {
	ll k;
	cin >> k;
	// ===== Step 1：定位第 k 位在哪个数 =====
	ll cur = 9, len = 1;
	while (k > cur * len) {
		k -= cur * len;
		cur *= 10;
		len++;
	}
	ll start = cur / 9; // 这一段起点（1, 10, 100...）
	ll num = start + (k - 1) / len; // 第 k 位所在的数
	int pos = (k - 1) % len + 1;    // 是这个数的第几位
	// ===== Step 2：DP 求 1 ~ num-1 的数位和 =====
	ll ans = calc(num - 1);
	// ===== Step 3：加上 num 的前 pos 位 =====
	string s = to_string(num);
	for (int i = 0; i < pos; i++) {
		ans += s[i] - '0';
	}
	cout << ans << '\n';
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