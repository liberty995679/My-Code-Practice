//对输入的数字，输出它的因子总和
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int N = 500000;
vector<ll> nums(N + 1, 0);
void solve() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            nums[j] += i;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    solve();
    while (t--) {
        ll x;
        cin >> x;
        cout << nums[x] - x << '\n';
    }
    return 0;
}
