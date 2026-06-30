//生成数组，满足条件x1=x,xi=(axi-1 + b) mod c(for i = 2, 3...n),
//在长度为k的窗口中取XOR，并对所有XOR进行异或计算,输出结果
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

vector<int> setarray(int n,int x, int a, int b, int c) {
    vector<int> res(n + 1, 0);
    res[1] = x;
    for (int i = 2; i <= n; i++) {
        res[i] = (a * res[i - 1] + b) % c;
    }
    return res;
}

void solve(const vector<int> &nums, int k) {
    int n = nums.size();
    int l = 1;
    int ans = 0;
    int XOR = 0;
    for (int r = 1; r < n; r++) {
        XOR ^= nums[r];
        while (r - l + 1 > k) {
            XOR ^= nums[l];
            l++;
        }
        if (r - l + 1 == k) {
            ans = ans ^ XOR; 
        }
    }
    cout << ans << endl;
}

signed main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, x, a , b, c;
    cin >> n >> k >> x >> a >> b >> c;
    vector<int>nums = setarray(n, x, a, b, c);
    solve(nums, k);
    return 0;
}