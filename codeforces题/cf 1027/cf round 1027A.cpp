//t个用例 每个用例输入一个字符串s代表年份
//0001 a = 00 b = 01 切割字符串
//if (a + b) ^ 2 == s 输出a b
//如果没有则输出 -1
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
#include <set>
using namespace std;
using ll = long long;

void solve() { 
    string s;
    cin >> s;
    int ans = stoi(s);
    int res = 0;
    for (int a = 0; a <= 99; a++) {
        for (int b = 0; b <= 99; b++) {
            res = (a + b) * (a + b);
            if (res == ans) {
                cout << a << ' ' << b << endl;
                return;
            }
        }
    }
        cout << -1 << endl;
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