//给两个字符串
//输出字典序小的那一个
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
    cout << (a < b ? a : b) << endl;
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