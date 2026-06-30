//cpu调度问题
//输入一个字符数组 和 n
//每个字符就是一个cpu任务进行工作，相同任务之间要隔着至少n个任务进程
//可以用idle 进行 空白代替
//计算完成全部cpu任务的最少时间
//输出一个整数即可
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;
using ll = long long;

void solve() {
    vector<char> a{'A','A','A','B','B','B'};
    int n;
    cin >> n;
    priority_queue<int> pq;
    vector<int> cnt(26);
    for (char& c: a) {
        cnt[c - 'A']++;
    }
    for (int& x: cnt) {
        if (x > 0) pq.push(x);
    }
    int res = 0;
    int t = 0;
    while (!pq.empty()) {
        int c = n + 1;
        int used = 0;  //执行次数
        vector<int> nums;
        while (!pq.empty() && c--) {
            int it = pq.top(); pq.pop();
            it--;
            if (it > 0) nums.push_back(it);
            used++;
            res++;
        }
        for (int& x: nums) {
            pq.push(x);
        }
        if (pq.empty()) break;
        res += (n + 1 - used);
    }
    cout << res << endl;
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
        solve();
    }
    return 0;
}