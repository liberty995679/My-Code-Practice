//组合锁旋转角度问题
//有n个输入的角度
//判断是否最后是否到0度
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;

void convert(const vector<int>& arr) {
    int n = arr.size();
    int cnt = (1 << n);
    bool flag = false;
    for (int c = 0; c < cnt; c++) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (c & (1 << i)) {  //检查c的第i位是否为1
                res += arr[i];
            } else {
                res -= arr[i];
            }
        }
        if (res % 360 == 0) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
}


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    convert(arr);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r" ,stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}