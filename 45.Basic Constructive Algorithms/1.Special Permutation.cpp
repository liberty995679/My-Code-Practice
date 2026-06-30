//构造一个数组，使他pi ！= i,坐标不等于数值
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<int> solve(int n) {
    vector<int> a;
    for (int i = n; i > 0; i--) {
        a.push_back(i);
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == i + 1) swap(a[i], a[i + 1]);
    }
    return a;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums = solve(n);
        for (int i: nums) cout << i << ' ';
        cout << endl;
    }
    return 0;
}