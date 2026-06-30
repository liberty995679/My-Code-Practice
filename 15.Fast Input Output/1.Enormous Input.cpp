//相乘输出
#include <iostream>

using namespace std;
using ll = long long;

ll solve(ll a, ll b) {
    return a * b;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << '\n';
    }
    return 0;
}