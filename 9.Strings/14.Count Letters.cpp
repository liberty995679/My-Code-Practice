//给一个字符串,只包含小写字母
//计算每一个字母出现次数，仅出现的字母
//输出 a : 3类似
//没说按字典序输出
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <cctype>
using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c: s) {
        mp[c]++;
    }
    for (auto i: mp) {
        cout << i.first << " : " << i.second << endl;
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