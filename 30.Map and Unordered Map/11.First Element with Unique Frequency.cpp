//给定一个整数数组 nums。
//返回一个整数，该整数表示 nums中频率唯一（即没有其他整数出现相同次数）的第一个元素（从左到右扫描）。
//如果不存在这样的元素，则返回 -1。
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <string>
#include <climits>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

int convert(vector<int> &nums) {
    int n = nums.size();
    vector<int> order;
    unordered_map<int, int> cnt_num, pos_num;
    for (int i: nums) {
        if (!cnt_num.count(i)) order.push_back(i);
        cnt_num[i]++;  //每个数的出现次数
    }
    for (auto it: cnt_num) { 
        pos_num[it.second]++;  //次数的记录数量
    }
    for (int i = 0; i < order.size(); i++) {
        int c = order[i];
        int cnt = cnt_num[c];
        if (pos_num[cnt] == 1) {
            return c;
        }
    }
    return -1;
} 

void solve() {
    int n;
    cin >> n;
    vector<int> nums = {20, 30, 10, 10};
    cout << convert(nums);
}

int main() {
#ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}