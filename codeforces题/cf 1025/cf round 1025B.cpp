//有 n * m 的格子, 怪物在起点(a, b)
//每个回合，Mouf先行动，可以切一次行或者列
//Mouf：想让回合数 最少（尽量多切掉）
//Fouad：想让回合数 最多（把怪物移到最难切的位置
//计算最优情况下的回合数
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

ll convert(ll n) {
    ll res = 0;
    while (n > 1) {
        if (n & 1) {
            n = (n + 1) / 2;
        } else {
            n /= 2;
        }
        res++;
    }
    return res;
}

void solve() {  
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    ll x, y;
    x = min(a, n - a + 1);  //x 和 y根据怪物位置切第一刀
    y = min(b, m - b + 1);
    ll ans1 = 0; 
    ll ans2 = 0;
    ans1 = 1 + convert(x) + convert(m);  //行或者列切过一次后，另一个是原来的数
    ans2 = 1 + convert(n) + convert(y);
    cout << min(ans1, ans2) << endl;
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