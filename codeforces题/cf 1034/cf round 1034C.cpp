//t个用例 长度n 数组a
//一次操作你可以选择：
//选择一个 非空前缀（即前 k个元素，k≥1），将其全部替换成这个前缀的 最小值；
//或者选择一个 非空后缀（即后 k个元素，k≥1），将其全部替换成这个后缀的 最大值。
//注意：你可以选择整个数组作为前缀或后缀。
//对于每个元素 ai，判断是否存在某种操作序列，使得最终数组变成
//输出一个长度为 n的二进制字符串，第 i个字符为 1表示可以变成 [a]，否则为 0。
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pre(n + 1), suf(n + 1);
    string s;
    pre[0] = a[0];
    suf[n] = a[n - 1];
    for (int i = 1; i < n; i++) {
        pre[i] = min(a[i], pre[i - 1]);
    }
    for (int i = n - 1; i > 0; i--) {
        suf[i] = max(a[i], suf[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        s += (a[i] == pre[i] || a[i] == suf[i]) ? '1' : '0';
    }
    cout << s << enl;
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