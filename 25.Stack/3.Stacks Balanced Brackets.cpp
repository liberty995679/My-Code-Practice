//平衡括号序列这些要成对'(', ')', '{', '}', '[' and ']'
//输入一个n 表示字符串的数量
//输入字符串只包含括号
//判断每一个字符串是不是平衡括号序列
//是就输出YES 否则输出NO
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
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        stack<char> st;
        bool flag = true;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if (!st.empty()) {
                    if (c == ')' && st.top() == '(') {
                        st.pop();
                    } else if (c == ']' && st.top() == '[') {
                        st.pop();
                    } else if (c == '}' && st.top() == '{' ){
                        st.pop();
                    }
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag && st.empty()) cout << "YES\n";
        else cout << "NO\n";
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