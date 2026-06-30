//差分,对a1加上b1到am加上bm，对a2加上b1到am+1加上bm，执行n-m+1次，输出数组a
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &a, vector<int> &b, int c) {
    int n = a.size() - 1;
    int m = b.size() - 1;
    vector<int> diff(n + 3);
    for (int i = 1; i <= m; i++) {
        int l = i;
        int r = n - m + i;
        diff[l] += b[i];
        if (r + 1 <= n) diff[r + 1] -= b[i];
    }
    int x = 0;
    for (int i = 1; i <= n; i++) {
        x += diff[i];          //加上增量
        a[i] += x;            
    }
    for (int i = 1; i <= n; i++) {
        a[i] = (a[i] % c + c) % c;  //防止负数
        if (i > 1) cout << ' ';
        cout << a[i];
    }cout << endl;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> nums(n+1), b(m+1);
    for (int i = 1; i <= n; i++) cin >> nums[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    solve(nums, b, c);
    return 0;
}