//t个用例 ，输入 a b (0 <= a, b <= 1e18)
//你可以执行两种操作
//同时增加​ a和 b各 1
//同时减少 a和 b各 1
//确定粉丝们能获得的最大兴奋程度以及达到该兴奋程度所需的最小操作次数
//如果粉丝可以获得无限的兴奋程度，输出 0 0
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

void solve() {    //gcd(a+k,b+k)=gcd(a+k,b−a)=gcd(a+k,d)
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll d = abs(a - b);  //最终 gcd 一定是 d 的因子，且最大可能就是 d 本身
        if (d == 0) {
            cout << 0 << ' ' << 0 << '\n';
            continue;
        }
        ll k = min(a % d, d - (a % d));  //最小操作次数 = 让 a（或 b）变成离它最近的 d 的倍数所需的步数
        cout << d << ' ' << k << '\n';
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