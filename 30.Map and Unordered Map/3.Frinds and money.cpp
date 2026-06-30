//你有n个朋友 其中第i个朋友有ai英镑
//给定q个查询
//1 x y: 其中x为名字 给x加y英镑
//2 x: 打印钱数
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
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n, q;
    cin >> n >> q;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string a; int c;
        cin >> a >> c;
        mp[a] = c;
    }
    while (q--) {
        int t,y; string x;
        cin >> t;
        if (t == 1) {
            cin >> x >> y;
            mp[x] += y;
        } else if (t == 2) {
            cin >> x;
            cout << mp[x] << enl;
        }
    }
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