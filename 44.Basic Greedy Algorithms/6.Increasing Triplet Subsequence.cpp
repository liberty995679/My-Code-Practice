//找一个数组的三个索引，索引递增的同时，他们所指的数据也是递增的,写一个类进行判断,递增的子序列
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

bool solve(const vector<int> &a) {
    int n = a.size();
    int first = INT_MAX;
    int second = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int x : a) {
            if (x <= first) { // 找到更小的起点
                first = x;
            } else if (x <= second) { // 找到比first大的更优second
                second = x;
            } else {  // x > second，说明存在first < second < x
                return true;
            }
        }
        return false; // 
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << solve(nums) <<endl;
    return 0;
}