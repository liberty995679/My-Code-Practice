//找C的因子，并且落在a-b的区间
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve (int n) {
    vector<int> nums;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            nums.push_back(i);
            if (i != n / i) nums.push_back(n / i);
        }
    }
    sort(nums.begin(), nums.end());
    return nums;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> c1 = solve(c);
    int count = 0;
    for (int i = 0; i <= c1.size(); i++) {
        if (c1[i] >= a && c1[i] <= b) count++;
    }
    cout << count << endl;
    return 0;
}