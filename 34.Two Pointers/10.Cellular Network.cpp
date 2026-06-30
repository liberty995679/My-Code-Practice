//蜂窝网络，一座蜂窝塔能覆盖n个城市，覆盖条件为每个城市距离蜂窝塔不超过r,求r的最小值，以便所有城市能被塔覆盖
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
using ll = long long;

int solve(const vector<int> &a, const vector<int> &b) {
    int j = 0;
    int n = a.size();
    int m = b.size();
    int res = 0;
    for (int i = 0; i < n; i++) { //遍历城市，找最近的塔
        while (j + 1 < m && abs(a[i] - b[j]) >= abs(a[i] - b[j + 1])) {
            j++;    //如果该城市距离j塔比j+1塔距离远,那就选j+1塔
        }
        int dis = abs(a[i] - b[j]);
        res = max(res, dis);
    }
    return res;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m; //城市的数量，塔的数量
    vector<int> city(n), tower(m);
    for (int i = 0; i < n; i++) cin >> city[i];
    for (int i = 0; i < m; i++) cin >> tower[i];
    sort(city.begin(), city.end());
    sort(tower.begin(), tower.end());
    cout << solve(city, tower) << '\n';
    return 0;
}