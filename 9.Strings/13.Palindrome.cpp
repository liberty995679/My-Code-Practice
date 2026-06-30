//给一个字符串判断是不是回文
//输出YES or NO
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

void solve() {
    string s;
    cin >> s;
    string a = s;
    reverse(a.begin(), a.end());
    if (a == s) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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