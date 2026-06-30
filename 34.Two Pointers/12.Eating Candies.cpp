//吃糖果，输出Alice和Bob能吃的总重相同的糖果数
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<int> &a) {
    int n = a.size();
    int sum1 = 0; //总重量
    int sum2 = 0;
    int l = 0;
    int r = n - 1;
    int ans1 = 1; int ans2 = 1;
    sum1 += a[l]; sum2 += a[r];
    int res = 0;
    while (l < r) { 
        if (sum1 == sum2) {
            res = ans1 + ans2;
            l++; r--;
            sum1 += a[l]; sum2 += a[r];
            ans1++; ans2++;
        }
        if (sum1 < sum2) {
            l++;  ans1++;
            sum1 += a[l];
        }
        if (sum1  > sum2) {
            r--;  ans2++;
            sum2 += a[r];
        }
        
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, w;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> num(n);
        for (int i = 0; i < n; i++) cin >> num[i];
        cout << solve(num) << endl;
    }
    return 0;
}