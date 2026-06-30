//三元删除操作
//对于m个元素的数组b，选择三个下标i, j, k
//下标对应的元素相同，然后将其删除
//一次该操作的代价是min(k - j, j - i)
//输入l和r
//在这个区间计算使数组变空的操作代价的最小总和
//如果不可能变空，输出-1
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <stack>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

vector<int> sumarr(const vector<int> &a) {
    int n = a.size();
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i]; //下标从1开始
    }
    return prefix;
}

void solve() {   //判断是否存在相邻相同的元素,如果有花费就是(l - r + 1) / 3
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> b(n + 1);
    for (int i = 1; i < n; i++)  {
        b[i] = (arr[i] == arr[i + 1] ? 1 : 0);
    }
    vector<int> prefix = sumarr(b);
    vector<int> pre1(n+1);
    for(int i = 1; i <= n; i++){
        pre1[i]= pre1[i - 1] + arr[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int cnt1 = pre1[r] - pre1[l - 1];  //区间内1的数量
        int cnt0 = (r - l + 1) - cnt1;
        if (cnt0 % 3 != 0 || cnt1 % 3 != 0) {
            cout << -1 << '\n';
            continue;
        }
        int sum = prefix[r - 1] - prefix[l - 1]; //要检查的是(l, l + 1) .... (r - 1, r) ,没有(r, r + 1)
        int ans = 0;
        if (sum > 0) {
            ans = (r - l + 1) / 3;
        } else {
            ans = 2 +  (r - l - 2) / 3;
        }
        cout << ans << '\n';
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