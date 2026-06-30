//t个用例 n代表序列p的长度
//构造一个序列 使得它 ai > ai -1 && ai > ai + 1可以删除
//构造的结果是删除操作最大化
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

void solve() {
    int n;
    cin >> n;
    vector<int> arr;
    arr.push_back(1);
    for (int i = n; i > 1; i--) {
        arr.push_back(i);
    }
    for (const auto& i: arr) {
        cout << i << ' ';
    }cout << '\n';
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