//计算矩形面积,统计所有矩形中满足hs < hi < hb 且 ws < wi < wb的矩形面积总和
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<vector<ll>> rectangles(1005, vector<ll>(1005, 0));
        vector<vector<ll>> sum(1005, vector<ll>(1005, 0));
        for (int i = 0; i < n; i++) {
            ll h, w;    //定义 sum[h][w] 表示所有高度为 h、宽度为 w 的矩形的面积之和。
            cin >> h >> w;
            rectangles[h][w] += h*w;   
        }
        for (int i = 1; i < 1005; i++) {
            for (int j = 1; j < 1005; j++) {
                 sum[i][j] = rectangles[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        for (int i = 0; i < q; i++) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;   //严格大于 hs, ws 且小于 hb, wb 的矩形
            cout << sum[hb - 1][wb - 1] - sum[hb - 1][ws] - sum[hs][wb - 1] + sum[hs][ws] << endl;
        }
    }
    return 0;
}