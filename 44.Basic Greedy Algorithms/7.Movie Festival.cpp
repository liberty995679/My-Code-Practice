//输入电影的开始时间和结束时间，求最多可以看几部电影
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct movie{
    int start;
    int end;
};

int solve(const vector<movie> &a) {
    int cnt = 0;
    int n = a.size();
    int lastend = 0;  // 上一部电影的结束时间
    for (auto &i: a) {
        if (i.start >= lastend) {
            cnt++;
            lastend = i.end;
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
    int n;
    cin >> n;
    vector<movie> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i].start >> nums[i].end;
    sort(nums.begin(), nums.end(), [] (const movie &a, const movie &b) {
        return a.end < b.end;
    });
    cout << solve(nums) << endl;
    return 0;
}