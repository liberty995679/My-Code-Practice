//输入n表示数组a的数量
//输入已经排好序的数组a
//输入q 表示查询数量
//每次查询一个数x 判断它是否存在于数组里
//如果它存在输出它的索引
//否则输出最接近该数字的最小整数的索引(大于)
//如果相同的数字多次出现,打印第一个出现的索引
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int idx = it - arr.begin() + 1;
        if (*it == x) {
            cout << "Yes " << idx << endl;
        } else {
            cout << "No " << idx << endl;
        }
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