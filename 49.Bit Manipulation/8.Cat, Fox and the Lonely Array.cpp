//给一个数组,找最小整数k,使得所有长度为k的连续子数组的按位或|结果都相等。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(const vector<int> &a) { 
    int n = a.size();
    int ans = 1;
    for (int bit = 0; bit < 20; bit++) {
        int last_pos = -1;  // 上一次出现该位的位置
        int max_gap = 0;    // 该位的最大间隔
        // 遍历数组，找到该位出现的所有位置
        for (int i = 0; i < n; i++) {
            if (a[i] & (1 << bit)) {  // 如果第 bit 位是 1
                if (last_pos != -1) {
                    max_gap = max(max_gap, i - last_pos);
                } else {
                    // 第一次出现，考虑从开头到这里的距离
                    max_gap = i + 1;
                }
                last_pos = i;
            }
        }
        // 考虑最后一次出现到数组末尾的距离
        if (last_pos != -1) {
            max_gap = max(max_gap, n - last_pos);
        }
        // 如果这个位在数组中出现过，更新答案
        if (last_pos != -1) {
            ans = max(ans, max_gap);
        }
    }
    cout << ans << '\n';
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