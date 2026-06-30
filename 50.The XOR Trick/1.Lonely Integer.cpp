//一个数组中有多组2个相同的数，只有一个单独的数，输出它
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void findlonely(const vector<int> &a) { //相同的数字异或为0
    int n = a.size();
    int res = 0;
    for (auto &i: a) {
        res ^= i;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    findlonely(arr);
    return 0;
}