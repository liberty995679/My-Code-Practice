//每个缆车的重量不能超过x，可以坐一个或者两个小孩，求最少需要几辆缆车可以把小孩全部带上
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int solve(const vector<int> &a, int x) {
    int l = 0;
    int n = a.size();
    int r = n - 1;
    int cnt = 0;  //缆车数量
    while (l <= r) {
        ll sum = a[l] + a[r];
        if (sum > x) {  
            r--;
            cnt++;
        } else {
            l++;
            r--;
            cnt++;
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