//构造一个完美字符串
//一个比特串为完美的，如果它包含的 101子序列数量与 010子序列数量相同
//定义为字符串中的1数量为k
//t个用例, n长度, k数量
//输出结果字符串
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
#include <map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s = string(k, '1');
    for (int i = k ; i < n; i++) s.append("0");
    cout << s << '\n';
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