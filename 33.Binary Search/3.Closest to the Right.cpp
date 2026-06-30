//二分查找，输出大于等于n的最小坐标
#include <iostream>
#include <vector>
using namespace std;


int solve(const vector<int> &a, int n) {
    int l = 0; int r = a.size(); //左闭右开区间
    while (l < r) {   
        int mid = l + (r - l) / 2; 
        if (a[mid] < n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    while (k--) {
        int x;
        cin >> x;
        int idx = solve(nums, x);
        cout << (idx >= 0 ? idx + 1: 0) << endl;
    }
    return 0;
}