//鞋子打乱,满足每个学生都要穿到大于等于鞋码的鞋
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
void solve(const vector<int> &a) {
    unordered_map<int, int> m; //记录相同鞋码的次数
    int n = a.size();
    for (int i = 0; i < n; i++) {
        m[a[i]]++;
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (m[a[i]] == 1) {
            flag = false;
        }
    }
    if (!flag) {
        cout << -1 << endl;
        return;
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (m[a[i]] != 0) {
            int pos = m[a[i]];
            for (int j = i + 1; j < i + pos; j++) {
                b.push_back(j + 1);     //往左移一位
            }b.push_back(i + 1);
            m[a[i]] = 0;
        }
    }
    for (const auto&i : b) {
        cout << i << ' ';
    }cout << endl;
    return;
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
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        solve(nums);
    }
    return 0;
}