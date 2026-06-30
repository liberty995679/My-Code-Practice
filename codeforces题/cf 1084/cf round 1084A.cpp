//吃饭游戏
//玩家i可以有ai个盘子
//每个回合大家都会吃饭
//到最后的人获胜
//计算最后有几个人
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int mx = 0;
    unordered_map<int, int> mp;
    for (int i: arr) {
        mp[i]++;
        mx = max(mx, i);
    }
    cout << mp[mx] << endl;
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