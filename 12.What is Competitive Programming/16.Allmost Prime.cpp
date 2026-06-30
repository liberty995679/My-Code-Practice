//输入n
//计算1到n的数字里有两个质因数的个数
//质因数是指能整除该数的质数
//例如 6 = 2 * 3,2 3都是质因数
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 0) {  //cnt[i] = i 有多少个不同的质因数
            for (int j = i; j <= n; j += i) {
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 2) {
            ans++;
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