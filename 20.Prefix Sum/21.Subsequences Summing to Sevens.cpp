//n头奶牛 站成一排
//拍摄编号之和为7的倍数的奶牛群
//计算他能拍摄的最大奶牛群的规模即连续奶牛的数量
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int ans = 0;
    unordered_map<int, int> mp;   //存储前缀和除以7的余数
    for (int i = 0; i <= n; i++) {
        int x = prefix[i] % 7;
        if (mp.find(x) == mp.end()) {
            mp[x] = i;
        } else {
            int length = i - mp[x];
            ans = max(ans, length);
        }
    }
    cout << ans << endl;
    
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("div7.in", "r", stdin);   
    freopen("div7.out", "w", stdout); 
    solve();
    return 0;
}