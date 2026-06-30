//有一个长度为n的数组a
//对于一个整数k，可以用任意次，将a变成非递减排序
//选择两个下标i 和 j， 满足|ai - aj| >= k ，然后交换ai 和 aj
//计算最大的整数k 
//如果不存在输出 -1
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (is_sorted(arr.begin(), arr.end())) {
        cout << -1 << '\n';
    } else {  
        vector<int> b = arr;
        sort(b.begin(), b.end());
        int k = INT_MAX;
        set<int> s;
        int mn = b[0]; int mx = b[n - 1];
        for (int i = 0; i < n; i++) {
            if (arr[i] != b[i]) {
                k = min(k, max(arr[i] - mn, mx - arr[i])); //对于任意错位的 a[i]，它一定能和 mn（最小值）或 mx（最大值）合法交换。
            }
        }
        cout << k << endl;
    }
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