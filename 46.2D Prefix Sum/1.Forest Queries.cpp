//二维前缀和,计算矩形范围内的树的数量
#include <iostream>
#include <vector>

using namespace std;
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<char>> nums(n + 1, vector<char>(n + 1, ' '));
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> nums[i][j];
            int val = (nums[i][j] == '*') ? 1 : 0;
            prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1] + val;
        }
    }
    while (q--) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1]<< endl;
    }
    return 0;
}