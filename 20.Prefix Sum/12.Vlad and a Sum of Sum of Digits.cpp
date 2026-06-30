//前缀和，将1-n转换成每个数位的和的数字，再求前缀和
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

const int MAX = 2e5 + 1;
vector<ll> sums(MAX, 0);

void solve() {
    for (int i = 1; i < MAX; ++i) {
        int j = i;
        ll x = 0;
        while (j > 0) {
            x += (j % 10);
            j /= 10;
        }
        sums[i] = sums[i - 1] + x;
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
        int n;
        cin >> n;
        cout << sums[n] << '\n';
    }
    return 0;
}