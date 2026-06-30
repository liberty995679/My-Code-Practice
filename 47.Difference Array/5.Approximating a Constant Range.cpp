//求数组的l,r区间的最大数与最小数的差值<=1,输出最长长度
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

void solve(const vector<int> &a) {
    int n = a.size();
    int l = 0;
    int maxlen = 1;  //记录最长长度 
    deque<int> maxdq, mindq;
    for (int r = 0; r < n; r++) {
        while (!maxdq.empty() && a[maxdq.back()] <= a[r]) {
            maxdq.pop_back();
        }
        maxdq.push_back(r);
        while (!mindq.empty() && a[mindq.back()] >= a[r]) {
            mindq.pop_back();
        }
        mindq.push_back(r);
        while (!maxdq.empty() && !mindq.empty() && a[maxdq.front()] - a[mindq.front()] > 1) {
            l++;
            if (maxdq.front() < l) maxdq.pop_front();
            if (mindq.front() < l) mindq.pop_front();
        }
        maxlen = max(maxlen, r - l + 1);
    }
    cout << maxlen << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    solve(nums);
    return 0;
}