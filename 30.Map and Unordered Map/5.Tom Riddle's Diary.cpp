//哈利·波特正在执行摧毁神秘人魂器的任务。他在密室中遇到的第一个魂器是汤姆·里德尔的日记。
//这本日记曾属于金妮，并迫使她打开了密室。哈利想知道所有曾经拥有过这本日记的人，以确保他们没有被日记控制。
//他按顺序记录了n个曾拥有日记的人名。你需要针对每个人，判断他/她之前是否曾经拥有过这本日记。
//具体来说，对于第i行的名字si，如果存在索引j满足si = sj且j < i，则输出"YES"（不带引号），否则输出"NO"（不带引号）。
//第一行输入包含一个整数n（1 ≤ n ≤ 100）——表示名单中人名的数量。
//接下来n行每行包含一个由小写英文字母组成的字符串si。每个字符串的长度在1到100之间。
//输出n行，每行包含"YES"或"NO"（不带引号），表示该字符串是否在之前已经出现过。
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
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (mp.find(s) != mp.end()) {
            cout << "YES" << enl;
        } else {
            cout << "NO" << enl;
        }
        mp[s]++; 
    }
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