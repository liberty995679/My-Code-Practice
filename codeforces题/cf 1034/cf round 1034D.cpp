//Alice 和 Bob 给定一个长度为 n的二进制字符串 s，以及一个整数 k（1≤k<n）。
//游戏规则如下：
//Alice 的目标是在有限步内将字符串的所有字符变成 0。
//如果 Alice 无法在有限步内获胜，则 Bob 获胜。
//两人轮流行动，Alice 先手。
//Alice 的回合：她可以选择字符串中任意长度为 k的子序列（不要求连续），将该子序列中的所有字符设为 0。
//Bob 的回合：他可以选择字符串中任意长度为 k的子串（必须连续），将该子串中的所有字符设为 1。
//注意：如果在游戏过程中的任意时刻（包括 Alice 回合结束后、Bob 回合开始前）字符串全为 0，则 Alice 立即获胜。
//问：在双方都采取最优策略的情况下，谁会获胜？
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
#include <list>
#include <map>
#include <set>
using namespace std;
using ll = long long;
const char enl = '\n';
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    for (auto it: s) {  //这题不是模拟 而是数学结论
        if (it == '1') cnt++; //字符串里任意两组大小为 k 的集合，必然相交
    }
    //任何两个大小为 k 的集合，一定会重叠相交
    //翻译成人话：不管 Bob 以后想在哪一段连续 k 个位置刷成 1那块区域，一定和 Alice 上次清零的区域重叠
    cout << (cnt <= k || 2 * k > n ? "Alice" : "Bob") << enl;
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