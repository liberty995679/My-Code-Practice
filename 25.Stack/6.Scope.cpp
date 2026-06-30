//有一个包含小写字母和括号的字符串
//主人公可以将小写字母先移除, 小写字母的球放进去
//如果球还在里面，还要放这个球，他会昏倒
//然后根据括号匹配，括号内的球可以取出来
//判断他是否能在不昏倒的情况下完全删除字符串
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
    stack<char> st;
    set<char> sch;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (st.empty()) {
                cout << "No\n";
                return;
            } 
            while (!st.empty()) {
                char x = st.top();
                if (x == '(') {
                    st.pop();
                    break;
                }
                sch.erase(x);
                st.pop();
            }
        } else {
            if (sch.find(s[i]) != sch.end()) {
                cout << "No\n";
                return;
            }
            st.push(s[i]);
            sch.insert(s[i]);
        }
    }
    cout << "Yes\n";
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