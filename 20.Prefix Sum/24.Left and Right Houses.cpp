//有n个房子 每个人希望
//0 : 住在道路左边 1 ：住在道路右边
//要在i位置 和 i + 1 修路 ,允许i = 0 or n
//左边有i个人, 右边有n - i个人
//两边都要取整 / 2 满足左边0的数量大，右边1的数量大
//输出位置i
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pre0(n + 1);
    for (int i = 1; i <= n; i++) {
        pre0[i] = pre0[i - 1] + (s[i - 1] == '0');
    }
    int ans = -1;
    int best = INT_MAX;
    for (int i = 0; i <= n; i++) {
        int left0 = pre0[i];   //左边的0的数量
        int need0 = (i + 1) / 2;
        int right0 = pre0[n] - pre0[i];  //右边的0的数量
        int right1 = n - i - right0;
        int need1 = (n - i + 1) / 2;
        if (left0 >= need0 && right1 >= need1) {
            int mid = abs(n - 2 * i); //中间位置  // 到中心距离的2倍
            if (mid < best || (mid == best && i < ans) ) {
                best = mid;
                ans = i;  //更新答案
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}