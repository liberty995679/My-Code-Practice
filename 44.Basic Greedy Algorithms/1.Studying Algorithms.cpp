//贪心算法，她有x分钟学习，每个算法都可以学习，求最多能学习的算法
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<int> &a, int x) {
    int res = 0;
    int cnt = 0;
    for (int i : a) {
        res += i;
        cnt++;
        if (res > x) {
            res -= i;
            cnt--;
            break;
        }
    }
    return cnt;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    cout << solve(nums, x) << endl;
    return 0;
}