//t个用例 有一个长度为n的字符串s 由a和b组成
//他想从字符串中删除一段连续的字母可以是0个
//使得删除后的字符串a b 数量相等
//可以从任意位置开始删除
//任务是确定需要删除多少连续的字母
//如果是删除整个字符串即变成空串，输出-1
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;    //区间和 = a数量 - b数量
    vector<int> pre(n + 1);
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i] = (s[i - 1] == 'a' ? 1 : -1);
    }
    pre[0] = 0;  //初始化 0
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }
    int asum = 0; int bsum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') asum++;
        else bsum++;
    }
    int ans =  INT_MAX;
    unordered_map<int, int> mp;   //存前缀值最早出现的位置
    mp[0] = 0;
    int d = asum - bsum;
    if (d == 0) {
        cout << 0 << endl;
        return;
    }
    for (int r = 1; r <= n; r++) {
        int target = pre[r] - d;
        if (mp.count(target)) { //先找目标
            int pos = mp[target];
            ans = min(ans, r - pos);
        }
        mp[pre[r]] = r;   //更新最新位置
    }
    if (ans == INT_MAX || ans == n) ans = -1; //如果是整个字符串
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