//前缀异或
#include <iostream>
#include <vector>

using namespace std;


int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> nums(n + 1);
    vector<int> sums(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        sums[i] = sums[i - 1] ^ nums[i];
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (sums[b] ^ sums[a - 1]) << '\n';
    }
    return 0;
}