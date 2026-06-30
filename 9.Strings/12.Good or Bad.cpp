//t个例子
//输入一个字符串
//判断它有没有010 或者 101字符串
//有就是输出Good 否则输出 Bad
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        size_t a = s.find("010");
        size_t b = s.find("101");
        if (a != string::npos || b != string::npos) {
            cout << "Good\n";
        } else cout << "Bad\n";
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