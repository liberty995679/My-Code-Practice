//找数组里ai+aj+j-i的最小值
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
    int ans = 1e9;
    for (int i = 0; i < n - 1; i++) {
        int cnt = 0;
        for (int j = i + 1; j < n; j++) {
            cnt = arr[i] + arr[j] + j - i;
            ans = min(cnt, ans);
        }
    }
    cout << ans << '\n';
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