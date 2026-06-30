//t个用例，数组a有n个数, 最后k个前缀和
//输入S(n - k + 1) 到 S(n) 的数
//a1 <= a2 <= a3 <= a4 
//给了部分前缀和，判断能否组成数组a
//输出YES or NO
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
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n + 1);
    vector<ll> prefix(n + 1);
    for (int i = n - k + 1; i <= n; i++) {
        cin >> prefix[i];
    }
    if (k == 1) {     //一个数永远递增
        cout << "YES" << endl;
        return;
    }
    for (int i = n - k + 2; i <= n; i++) {  //还原部分a
        arr[i] = prefix[i] - prefix[i - 1];
    }
    if (!is_sorted(arr.begin() + n - k + 2, arr.end())) { //如果非递增
        cout << "NO\n";
        return;
    }
    if (prefix[n - k + 1] > arr[n - k + 2] * (n - k + 1)) {  //a1 + a2 + a3 + a4 = s4
        cout << "NO\n";       //a1 <= a2 <= a3 <= a4    a1 + a2 + a3 <= 3 * a4
        return;               // s4 / 4 <=  a4 <= a5
    }
    cout << "YES\n";
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