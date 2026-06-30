//t个用例 n长度 s字符串只包含0 1
//每次操作选择头或者尾
//将他们翻转,再插入到任意位置
//输出让他们全部一样的最小操作数
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    int n; string s;
    cin >> n >> s;
    int cnt0 = 0; int mx0 = 0; int count0 = 0;
    int cnt1 = 0; int mx1 = 0; int count1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            count0++;   //0 的总数
            cnt0++;
            mx0 = max(cnt0, mx0);  //0 的最长连续段
            cnt1 = 0;
        } else {
            count1++;  //1 的总数
            cnt1++;
            mx1 = max(mx1, cnt1); // 1 的最长连续段
            cnt0 = 0;
        }
    }
    ll ans = 0;
    ll ans1 =count1 + (count0 - mx0) * 2;  //全变成0 1的贡献加上 全0减去(连续0)d的贡献
    ll ans2 = count0 + (count1 - mx1) * 2; //同理, 全变成1
    ans = min(ans1, ans2);
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