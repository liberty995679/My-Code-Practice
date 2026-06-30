//打印一个数组的所有子数组的最大值
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
    for (int i = 0; i < n; i++) {
        int cnt = arr[i];
        cout << cnt << ' ';
        for (int j = i + 1; j < n; j++) {
            int cur = arr[j];
            cnt = max(cnt, cur);
            cout << cnt << ' ';
        }
    }cout << '\n';
}


void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        convert(arr);
    }
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