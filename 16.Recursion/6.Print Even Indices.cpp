//递归，输出偶数位的数字
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve (int n, vector<int> arr) {
    if (n < 0) return;
    if ((n & 1) == 0) cout << arr[n] << " ";
    solve(n - 1, arr);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    solve(n - 1, arr);
    return 0;
}