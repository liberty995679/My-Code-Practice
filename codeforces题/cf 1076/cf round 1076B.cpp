//t个用例 n数组长度
//给一个排列p
//[2,3,1,5,4]是一个排列，但 [1,2,2]和 [1,3,4]不是排列
//选择两个整数 l,r（1≤l≤r≤n），将排列 p中区间 [l,r]的元素反转
//输出执行一次该操作后能得到的最大字典序排列
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> p = arr;
    sort(p.begin(), p.end(), greater<int>());
    int l = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != p[i]) {
            l = i;
            break;
        }
    }
    if (l != -1) {
        int r = -1;
        int mx = arr[l];
        for (int i = l + 1; i <n; i++) {
            if (arr[i] > mx) {
                mx = arr[i];
                r = i;
            } 
        }
        reverse(arr.begin() + l, arr.begin() + r + 1);
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
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