//n个例子
//给两个字符串s ， t
//拼接成一个新的字符串
//前者的第i个字符跟上后者的第i个字符
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <cctype>
using namespace std;

void solve() {
    int n;
    cin >> n;
    while (n--) {
        string s, t;
        cin >> s >> t;
        string res;
        int len = min(s.size(), t.size());
        for (int i = 0; i < len; i++) {
            res += s[i];
            res += t[i];
        }
        if (s.size() > t.size()) {
            res += s.substr(len);
        } else {
            res += t.substr(len);
        }
        cout << res << endl;
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