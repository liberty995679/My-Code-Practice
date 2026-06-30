//给你一个长度为 n 的字符串 s，由小写拉丁字母组成。判断是否存在三个非空字符串 a、b、c，使得：
//a + b + c = s，意思是把字符串 a、b、c 按顺序拼接起来等于 s。
//字符串 b 是字符串 a + c 的一个子串，这里 a + c 是 a 和 c 拼接的结果。
//拼接定义：字符串 a 和 b 的拼接 a + b 是把 a 的所有字符后面接上 b 的所有字符。例如 "code" 和 "forces" 拼接得到 "codeforces"。
//子串定义：字符串 a 是字符串 b 的子串，如果可以从 b 的开头删掉若干字符（可以是 0 个或全部），再从末尾删掉若干字符（可以是 0 个或全部），得到 a
//t个用例 n长度 字符串s
//如果可以分解输出 Yes 否则输出 No
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
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<char> se;
    se.insert(s[0]);
    se.insert(s[n - 1]);
    bool flag = false;
    for (int i = 1; i < n - 1; i++) {
        if (se.count(s[i])) {
            flag = true;
            break;
        } else {
            se.insert(s[i]);
        }
    }
    if (flag) cout << "Yes" << enl;
    else cout << "No" << enl;
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