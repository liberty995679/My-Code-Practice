//抓宝可梦，求他要拜访的最小房子数,即在一个连续数组里找一个最小的子数组，使得它包含的不同字母最多
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solve(const string &s) {
    unordered_set<char> allnum(s.begin(), s.end()); //记录宝可梦所有类型数量
    int n = s.size();
    int l = 0;
    int res = INT_MAX;
    unordered_map<char, int> nownum;
    int sum = 0;     //窗口内类型数量
    for (int r = 0; r < n; r++) {
        nownum[s[r]]++;        //统计当前窗口的类型
        if (nownum[s[r]] == 1) sum++;
        while (sum == allnum.size()) {   //等于总类型
            res = min(res, r - l + 1);   //符合条件，取最小值
            nownum[s[l]]--;    //左边缩小，减去一个
            if (nownum[s[l]] == 0) sum--;  //当前窗口已经没有这个宝可梦，则类型减一
            l++;
        }
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;  //公寓数量
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}