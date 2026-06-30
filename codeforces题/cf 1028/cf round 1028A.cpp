//t个用例 输入a b c d
//表示G的生命 F的生命 G骑士的生命 F骑士的生命
//按回合制进行游戏
//如果k为奇数G骑士还活着 可以攻击F或者F骑士 使其生命-1
//K为偶数则是F骑士攻击
//对于每个测试用例，如果 Flower 会赢，输出 "Flower"
//否则输出 "Gellyfish"。
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int mx1 = min(a, c);
    int mx2 = min(b, d);
    if (mx1 < mx2) {
        cout << "Flower\n";
    } else {
        cout << "Gellyfish\n";
    }
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