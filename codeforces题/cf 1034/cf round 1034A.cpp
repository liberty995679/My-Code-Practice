//最初，黑板上写着从 0到 n−1的整数。
//每一轮：
//Alice 在黑板上选择一个整数 a并擦掉它；
//然后 Bob 在黑板上选择一个整数 b，满足a+b≡3(mod4)并擦掉它。
//轮次依次进行，直到某位玩家无法进行移动 —— 第一个无法移动的玩家输。
//问在双方都采取最优策略的情况下，谁会获胜。
//（注：x≡y(modm)表示 x−y是 m的整数倍。）
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
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n;
    cin >> n;
    cout << ((n % 4 != 0) ? "Alice" : "Bob") << enl;
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