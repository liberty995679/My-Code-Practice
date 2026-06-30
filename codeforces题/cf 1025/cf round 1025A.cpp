//有n个玩家进行决斗比赛
//有人会撒谎，导致结果不对
//输入数组a ， 1表示该玩家胜利过，0表示输家
//判断是否存在撒谎的人
//如果有撒谎输出YES 否则输出NO
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;

void solve() {  
    int n;
    cin >> n;
    vector<int> arr(n);
    int cnt0 = 0; int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt0 += (arr[i] == 0 ? 1 : 0);
        cnt1 += (arr[i] == 1 ? 1 : 0);
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (arr[i] == 0 && arr[i - 1] == 0) {
                flag = true;
                break;
            }
        }
    }
    if (cnt0 == n || cnt1 == n || flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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