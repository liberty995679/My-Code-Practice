//给两个字符串
//输出各自的大小，拼接后的结果，首字母互换的结果
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    cout << a.size() << ' ' << b.size() << endl;
    cout << a + b << endl;
    cout << b[0] + a.substr(1) << ' ' << a[0] + b.substr(1) << endl;
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