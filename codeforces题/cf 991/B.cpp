// 你有一个长度为 n 的数组 a。
// 在一次操作中，你可以选择一个下标 i（满足 2 ≤ i ≤ n−1），并执行以下两种动作之一：
// 将 a[i−1] 减 1，同时将 a[i+1] 加 1
// 将 a[i+1] 减 1，同时将 a[i−1] 加 1
// 每次操作后，所有元素的值必须保持非负。​
// 问：是否可以通过任意次操作，使得数组中所有元素都相等？
// 输入格式
// 第一行包含一个整数 t（1 ≤ t ≤ 10^4）——测试用例的数量。
// 每个测试用例的第一行包含一个整数 n（3 ≤ n ≤ 2·10^5）。
// 每个测试用例的第二行包含 n 个整数 a[i]（1 ≤ a[i] ≤ 10^9）。
// 保证所有测试用例的 n 之和不超过 2·10^5。
// 输出格式
// 对于每个测试用例：
// 如果可以通过若干次操作使所有元素相等，输出 "YES"
// 否则输出 "NO"
// 输出不区分大小写，例如 "yes"、"YeS"、"nO" 都会被判为正确。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll odd = 0; ll odd_cnt = 0;
    ll even = 0; ll even_cnt = 0;
    for (int i = 0; i < n; i+=2) {
        odd += arr[i];
        odd_cnt++;
    }
    for (int i = 1; i < n; i+=2) {
        even += arr[i];
        even_cnt++;
    }
    ll x = odd / odd_cnt;
    if (odd % odd_cnt == 0 && even_cnt * x == even) {
        cout << "YES" << enl;
    } else {
        cout << "NO" << enl;
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