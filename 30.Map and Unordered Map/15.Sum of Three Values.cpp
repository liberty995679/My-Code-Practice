//给一个n
//找三个数之和等于 x 
//输入n x
//输入数组a
//输出三个数(位置不同)
//没有解就输出IMPOSSIBLE
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


void solve() {
    ll n, x;
    cin >> n >> x;
    map<ll, vector<ll>> mp; //存数和所有的位置 有重复的数
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        arr[i] = a;
        mp[a].push_back(i + 1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll target = x - arr[i] - arr[j];
            if (mp.count(target)) { //用 map 查找 x - a[i] - a[j] 是否存在第三个数，并确保位置不同
                for (ll p: mp[target]) {
                    if (p != i + 1 && p != j + 1) {
                        cout << i + 1 << ' ' << j + 1 << ' ' << p << enl;
                        return;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << enl;
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