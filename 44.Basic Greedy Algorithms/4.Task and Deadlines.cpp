//完成各种任务，有持续时间和截止时间，本人的完成时间减去任务截止时间为奖励，求最多的奖励
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct task {
    int duration;
    int deadline;
};

bool cmp(const task &a, const task &b) {
    if (a.duration != b.duration) return a.duration < b.duration;
    return a.deadline > b.deadline;
}

ll solve(const vector<task> &a) {
    ll finish = 0;
    ll reward = 0;
    for (auto &i: a) {
        finish += i.duration;
        reward += (i.deadline - finish);
    }
    return reward;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<task> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i].duration >> nums[i].deadline;
    sort(nums.begin(), nums.end(), cmp);
    cout << solve(nums) << endl;
    return 0;
}