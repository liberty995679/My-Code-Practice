//q个查询
//1 x y 为x 加y 分
//2 x 删除学生x 的分数
//3 x 打印x的分数
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
    int q;
    cin >> q;
    unordered_map<string,int> mp;
    while (q--) {
        int tt, y;
        string  x;
        cin >> tt; 
        if (tt == 1) {
            cin >> x >> y;
            mp[x] += y;
        }else if (tt == 2) {
            cin >> x;
            mp.erase(x);
        } else {
            cin >> x;
            cout << mp[x] << enl;
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}