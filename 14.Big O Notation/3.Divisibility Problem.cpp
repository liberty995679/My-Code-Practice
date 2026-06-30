//判断a是否被b整除，是就输出0，如果不是输出a能被b整除要加的数量
#include <iostream>

using namespace std;
using ll = long long;

ll divise (ll a, ll b) {
    ll res;
    if (a % b == 0) return 0;
    res = b - a % b;
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << divise(a, b) << endl;
    }
    return 0;
}