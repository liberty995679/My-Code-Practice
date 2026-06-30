//将一个二进制字符串删除一个数位
//使其最大
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            s.erase(i, 1);
            break;
        }
    }
    if (s.size() == n) s = s.substr(0, n -1);
    cout << s << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}