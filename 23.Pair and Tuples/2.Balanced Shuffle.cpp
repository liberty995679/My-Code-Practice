//平衡括号序列的平衡洗牌
//序列"(()(("的平衡值是3
//对于输入序列的每个字符，计算该字符前的前缀平衡值
//然后按前缀平衡值升序排列表格的列，平衡值相同时按位置降序排列
//输入一个平衡括号序列
//输出它的平衡洗牌结果
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
    unordered_map<int, char> mp;
    vector<int> prefix(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        mp[i] = s[i];
        if (i > 0) {
            cur += (s[i - 1] == '(' ? 1 : -1);
            prefix[i] = cur;
        }
    }
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {i, prefix[i]};
    }
    sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first;
    });
    string ans;
    for (int i = 0; i < n; i++) {
        int p = arr[i].first;
        int q = arr[i].second;
        ans += mp[p];
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