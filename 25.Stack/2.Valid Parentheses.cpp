//给一个字符串
//它包含'(', ')', '{', '}', '[' and ']'
//判断它是否有效
//输出true 或者 false
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
    stack<char> st;
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                flag = false;
                break;
            }
        }
        if (s[i] == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                flag = false;
                break;
            }
        }
        if (s[i] == '}') {
            if (!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                flag = false;
                break;
            }
        }
    }
    if (flag && st.empty()) { // 栈为空代表没符号
        cout << "true"  << endl;
    } else {
        cout << "false" << endl;
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