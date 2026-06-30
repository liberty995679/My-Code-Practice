//输入一个字符串，只包括()平衡序列
//判断在删除一个()后，平衡是否会被打破
//空字符串是平衡序列
//如果会被打破平衡输出YES
//否则输出NO
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
    int n = s.size();
    s = s.substr(1, n - 2);
    stack<char> st;
    if (s.empty()) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else {
            if (!st.empty()) st.pop();
        }
    }
    if (st.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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