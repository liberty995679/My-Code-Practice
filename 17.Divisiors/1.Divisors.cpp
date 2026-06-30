//找因子
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
    int n;
    cin >> n;
    vector<int> nums = solve(n);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}