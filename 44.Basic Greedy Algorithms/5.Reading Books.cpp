//两人可以同时读书，每个人都要读完所有书本,求最少花费的时间
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solve(const vector<int> &a) {  //找最花时间的书
    ll sum = 0;
    int bookmax = *max_element(a.begin(), a.end());
    for (int i: a) {
        sum += i;
    }
    if (sum < 2 * bookmax) sum = 2 * bookmax; //两者比较
    return sum;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << solve(nums) << endl;
    return 0;
}