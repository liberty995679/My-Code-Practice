//给定一个整数 x。你需要找到最小的非负整数 y，
//使得数字 x 和 y 至少有一个相同的数字。
//换句话说，必须存在一个十进制数字 d，它同时出现在 x 和 y 的表示中。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
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

void solve(){
    int n;
    cin >> n;
    string s = to_string(n);
    for (int i = 0; i <= 9; i++) {
        if (s.find(to_string(i)) != string::npos) {
            cout << i << enl;
            return;
        } 
    }
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