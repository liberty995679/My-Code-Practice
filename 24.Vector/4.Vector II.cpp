//输入n q
//对于动态数组a 执行以下操作
//0 t x 表示在 At的末尾添加元素x
//1 t 表示 打印At中的所有元素
//2 t 表示 清空At 
//对于每个dump操作，输出At的元素
//最后一个元素不打印空格
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> arr(n);
    while (q--) {
        int p, t, x;
        cin >> p;
        if (p == 0) {
            cin >> t >> x;
            arr[t].push_back(x);
        } else if (p == 1) {
            cin >> t;
            for (int i = 0; i < arr[t].size(); i++) {
                if (i > 0) cout << ' ';
                cout << arr[t][i];
            }cout << endl;
        } else {
            cin >> t;
            arr[t].clear();
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE   //Aizu 不能用这个 ，记得注释掉
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}