//当数组中的x 在数组中出现x次，这种数组称为好序列
//输入n 和数组a的元素
//计算需要移除的最小元素数量
//空数组也可以是好序列
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
#include <set>
using namespace std;
using ll = long long;

void solve() { 
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= n) cnt[x]++;
        else ans++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] != 0) {
            if (cnt[i] > i) {
                ans += cnt[i] - i;
            } else if (cnt[i] < i) {
                ans += cnt[i];
            }
        }
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}