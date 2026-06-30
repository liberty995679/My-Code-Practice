//对于一个动态数组a
//有q个查询操作
//0 x 表示数组末尾添加x
//1 p 表示输出数组a[p]
//2 表示删除最后一个元素
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
    int q;
    cin >> q;
    vector<int> arr;
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int x;
            cin >> x;
            arr.push_back(x);
        } else if (type == 1) {
            int p; 
            cin >> p;
            cout << arr[p] << endl;
        } else if (type == 2) {
            arr.pop_back();
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE   //Aizu 的OJ 用不了这个 记得注释掉
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}