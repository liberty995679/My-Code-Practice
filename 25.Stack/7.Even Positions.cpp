//一个字符串只包含()
//(())()的计算数是 3 + 1 + 1 = 5
//t个用例 只给_)_)_)不完整的字符
//贪心选择，使其变为最小花费
//输出最小花费
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
    int n;
    string s;
    cin >> n >> s;
    string ans = s;
    ll res = 0;
    int cnt = 0;  //cnt 是平衡值 当前未匹配的左括号数量
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '_') {
            cnt += (cnt > 0 ? -1 : 1);  
        } else {
            cnt += (s[i] == '(' ? 1 : -1);  //每个 '(' 的贡献 = 它等待匹配的时间
        }
        res += cnt;
    }
    cout << res << endl;
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