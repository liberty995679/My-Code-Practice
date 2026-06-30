//你得到一个包含 1 到 n 每个数恰好一次的数组。
//你的任务是从左到右收集数字，按 1 到 n 的顺序收集。
//在每一轮中，你从左到右遍历数组，能收集多少就收集多少（即当前轮能收集到当前需要的下一个数字，以及它之后在数组里连续出现的、且正好是你接下来需要的数字）。
//问：总共需要多少轮才能收集完 1 到 n 的所有数字。
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
#include <unordered_set>
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = i;  //位置映射
    }
    int cnt = 1;
    for (int i = 1; i < n; i++) {  //i 在 i-1 的左边 你这一轮已经走过 i 了（但当时还不能拿）
                                         //必须重新从头开始扫！
        if (a[i] > a[i + 1]) cnt++;
    }
    cout << cnt << enl;
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