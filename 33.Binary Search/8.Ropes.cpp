//切绳子，将n条绳子切成k条相同长度的绳子，求最大能切的长度
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double piece(double mid,const vector<double> &a) { //能切出来的绳子数量
    double cnt = 0;
    for (const auto& i: a) {
        cnt += int(i / mid); //必须取整，否则会算出部分绳子
    }
    return cnt;
}

double solve(int right, int k, const vector<double> &a) {
    double l = 0;double r = (double)right;
    double res;
    while (r - l > 1e-6) {  //浮点二分，精度判断
        double mid = l + (r - l) / 2;
        res = piece(mid, a);
        if (res >= k) l = mid + 1e-7;  //让区间稍微推进，加快收敛
        else r = mid - 1e-7;
    }
    return l;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    double right = 1;
    vector<double> nums;
    while (n--) {
        double num;
        cin >> num;
        nums.push_back(num);
        right = max(right, num);
    }
    cout << fixed << setprecision(7);
    cout << solve(right, k, nums) << '\n';
}