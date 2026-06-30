//三个能量晶体，一开始全是0
//充能条件为选择一个i和一个j配对
//满足ai >= aj / 2也就是最大值是最小值的两倍
//t个用例 输入x
//判断三个晶体充能达到x 需要多少次
// 0 0 0 -> 1 1 1 各一次
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
#include <set>
using namespace std;
using ll = long long;

void solve() {
    int x;
    cin >> x;
    int k = 0;
    while ((1 << k) <= x) { //2 ^ k >= x (k >= 1)
        k++;    
    }
    int ans = 2 * k + 1;  //第一次是3步，接下来每一轮是2步 3 + 2 * (k - 1) 
    cout << ((x == 1) ? 3 : ans )<< endl;
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