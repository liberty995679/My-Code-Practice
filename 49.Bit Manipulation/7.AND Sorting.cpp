//有一个无序排列p,存在x = pi&pj ,对pi pj进行换位,求x的最大值
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> &a) { //根据测试用例可知，x等于无序数的&运算和
    int x = 0;
    int n = a.size();
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (!flag && a[i] != i) {
            x = a[i];
            flag = true;
        }
        if (flag && a[i] != i) {
            x &= a[i];
        }
    }cout << x << endl;
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        solve(nums);
    }
    return 0;
}