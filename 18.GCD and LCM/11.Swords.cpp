//n 种 剑 ai表示第i种类型的剑未被触动的数量
//每种类型的剑恰好有 x把。
//有 y个人闯入了地下室，每个人从某一种类型的剑中恰好拿走 z把剑。
//注意：不同的人可能拿走了不同类型的剑。
//注意：对你来说，x、y、z都是未知的
//输出y和 z—— 可能闯入地下室的最少人数，以及每人拿走的剑数
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <stack>
#include <unordered_map>
#include <climits>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return a / gcd(a, b) * b;
}

void solve() {     
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    ll g = 0;
    ll maxnum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        maxnum = max(maxnum, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        g = gcd(g, abs(arr[i] - maxnum));
    }
    ll y = (n * maxnum - sum) / g;
    ll z = g;
    cout << y << ' ' << z << endl;
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