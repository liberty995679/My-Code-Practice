//分钱，把钱x给最富有的人，根据平均值看看谁不开心，如果不开心人数已经大于一半，输出0
//没有大于一半，则要给钱，求x的最小值
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;


ll solve (int n, ll sum, const vector<int> &a) {
    ll l = 0; ll r = 1e12;
    while (l < r) {
        ll x = l + (r - l) / 2;
        double res = (double)sum + (double)x;
        double avg = res / n;
        ll cnt = 0;
        for (const auto& i: a) {
            if (i < avg / 2) cnt++;
        }
        if (cnt <= n / 2) l = x + 1;
        else r = x;
    }
    return l;
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
        ll sum  = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }
        if (n == 1 || n == 2) {
            cout << -1 << endl;
            continue;
        }
        double avg = (double)sum / n; //平均值
        int cnt = 0;
        for (const auto& i: nums) {
            if (i < avg / 2) cnt++;
        }
        if (cnt > n / 2) cout << 0 << endl;
        else {
            ll ans = solve(n, sum, nums); // 再次验证是否真的能超过一半
            double final_avg = (sum + ans) / (double)n;
            int final_cnt = 0;
            for (auto i : nums)
                if (i < final_avg / 2) final_cnt++;
            if (final_cnt < n / 2) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
    return 0;
}