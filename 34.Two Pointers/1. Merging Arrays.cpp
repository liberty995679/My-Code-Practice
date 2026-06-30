//双指针,数组合并
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c.push_back(a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < c.size(); i++) {
        if (i == c.size() - 1) {
            cout << c[i];
            return 0;
        }
        cout << c[i] << ' ';
    }
    return 0;
}