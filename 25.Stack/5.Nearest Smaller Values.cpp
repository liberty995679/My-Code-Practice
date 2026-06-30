//输入一个数组
//找到每个元素左侧一个具有较小值的位置
//输出每个位置, 第一个数左侧没有数，所以是0
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
    stack<int> st;  //存坐标
    vector<int> arr(n + 1);
    vector<int> ans(n + 1); //存结果坐标
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) { 
            st.pop();  //如果栈首的元素比他大
        }
        if (!st.empty()) {
            ans[i] = st.top();
        } else {
            ans[i] = 0; 
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i < n) cout << ' ';
    }cout << endl;
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