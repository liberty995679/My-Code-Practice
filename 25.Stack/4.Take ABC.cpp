//输入字符串s
//每一步操作是删除s子串中最左边的ABC子串(连续的)
//输出最后的结果
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
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'C') {
            st.push(s[i]);
            if (st.size() >= 3) {
                char c = st.top(); st.pop();
                char b = st.top(); st.pop();
                char a = st.top(); st.pop();
                if (a == 'A' && b == 'B' && c == 'C') {
                    continue;
                } else {
                    st.push(a); st.push(b); st.push(c);
                }
            }
        } else {
            st.push(s[i]);
        }
    }
    string ans;
    while (!st.empty()) {
        char c = st.top();
        ans = c + ans;
        st.pop();
    }
    cout << ans << endl;
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