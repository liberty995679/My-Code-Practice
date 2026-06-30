//输入
//第一行包含一个字符串 S
//第二行包含整数 X
//限制条件
//|S|=3
//0≤X≤109
//保证输入有效。
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

//S 的长度是 3，有什么著名的三个字母编程竞赛吗？

//大写变量字母和 "约束条件 "部分是为了模仿 [atcoder.jp](http://atcoder.jp) 的问题陈述格式而设计的。

//问题是询问 [Atcoder 竞赛](https://atcoder.jp) (ABC,ARC,AGC) 的评分是否为 X 。
//(注意，为简单起见，评委忽略 Atcoder 启发式竞赛）。

//- ABC 的评级为 $[0,1999]$ 。
//- ARC 的评级为 $[0,2799]$ 。
//- AGC 的评级为 $[1200,\infty]$ 。
void solve(){
    string s; int n;
    cin >> s >> n;
    if (s == "ABC" && n < 2000 || s == "ARC" && n < 2800 || s == "AGC" && n >= 1200) {
        cout << "YES" << enl;
    } else {
        cout << "NO" << enl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}