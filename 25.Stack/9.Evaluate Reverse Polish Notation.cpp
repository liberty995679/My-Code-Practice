//逆波兰表达式
//输入数字和计算符号
//输出结果
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
    vector<string> arr = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int n = arr.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/") {
            if (arr[i] == "+") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int cur = a + b;
                st.push(cur);
            } else if (arr[i] == "-") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int cur = a - b;
                st.push(cur);
            } else if (arr[i] == "*") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int cur = a * b;
                st.push(cur);
            } else if (arr[i] == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int cur = a / b;
                st.push(cur);
            }
        } else {
            int x = stoi(arr[i]);
            st.push(x);
        }
    }
    cout << st.top() << endl;
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