//输入一个字符串包含a和b俩个字符
//要让其中一个连续，另外一个分成两边
//可以选择一个位置i进行i+1的交换
//计算最少操作次数
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
    vector<ll> p1, p2;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') p1.push_back(i);
        else p2.push_back(i);
    }
    int nn = p1.size(); int mm = p2.size();
    vector<ll> b1(nn), b2(mm);
    for (int i = 0; i < p1.size(); i++) {
        b1[i] = p1[i] - i;
    }
    for (int i = 0; i < p2.size(); i++) {    // |pi - i - L|
        b2[i] = p2[i] - i;
    }
    int mid1 = b1.size() / 2;
    int mid2 = b2.size() / 2;   //找中位数
    ll cost1 = 0; ll cost2 = 0;
    for (int i = 0; i < b1.size(); i++) {
        cost1 += abs(b1[i] - b1[mid1]);
    }
    for (int i = 0; i < b2.size(); i++) {
        cost2 += abs(b2[i] - b2[mid2]);   // 要使得|bi - L|最小，L == 中位数
    }
    ll ans = min(cost1, cost2);
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