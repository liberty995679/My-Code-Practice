//在6 * 6 的数组中找小时玻璃
//构成为 a b c
//         d
//      e f g
//输出在这个数组的小时玻璃总和的最大值
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

ll convert(vector<vector<int>> &a, int x, int y) {
    ll sum = 0;
    sum += a[x][y];
    sum += a[x + 1][y];
    sum += a[x + 1][y - 1];
    sum += a[x + 1][y + 1];
    sum += a[x - 1][y];
    sum += a[x - 1][y - 1];
    sum += a[x - 1][y + 1];
    return sum;
}

void solve() {
    vector<vector<int>> arr(6, vector<int>(6));
    for (int i = 0; i < 6; i ++) {
        for (int  j =0 ; j < 6; j++) cin >> arr[i][j];
    }
    ll ans = LLONG_MIN;
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            ll sum = convert(arr, i, j);
            ans = max(ans, sum);
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