//二分查找，输出在区间内有多少个数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solve(const vector<int> &a, int left, int right) {
    int l = 0; int r = a.size(); //左闭右开区间
    while (l < r) {   
        int mid = l + (r - l) / 2; 
        if (a[mid] < left) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    int left_index = l;  //第一个大于等于left的数
    l = 0; r = a.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] <= right) {
            l = mid + 1;
        } else r = mid;
    }
    int right_index = l - 1;  //最后一个小于等于right的数
    return right_index - left_index + 1;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        int res = solve(nums, l, r);
        cout << max(0, res) << ' ';
    }
    return 0;
}