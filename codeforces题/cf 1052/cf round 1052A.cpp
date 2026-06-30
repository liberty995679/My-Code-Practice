//我们称一个数组为 平衡的，当且仅当其中任意元素出现的次数都相同。
//例如，[1,1,3,3,6,6]和 [2,2,2,2]是平衡的，但 [1,2,3,3]不是平衡的（因为元素 1 和 3 的出现次数不同）。
//注意：空数组始终是平衡的。
//给定一个长度为 n的非递减数组 a，请你找出它的 最长平衡子序列​ 的长度。
//*子序列定义：如果从原序列 a中任意删除若干（可以是零个或全部）元素后得到的序列为 b，则称 b是 a的一个子序列。
//t个用例 n长度 数组a
//输出结果
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (cnt[j] >= i) {
                sum++;
            }
        }
        sum = sum * i;
        res = max(res, sum);
    }
    cout << res << '\n';
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