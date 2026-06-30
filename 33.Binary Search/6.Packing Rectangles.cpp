//二分查找，用正方形包装多个矩形，输出最小正方形的长度
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif 
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll w, h, n;                    //每行能放的个数 = floor(x / w)
    cin >> w >> h >> n;             //每列能放的个数 = floor(x / h)  
    ll left = 1;                   //总数 = floor(x/w) * floor(x/h)。
    ll right = max(w, h) * n;              //我们要找最小的 x，满足这个总数 ≥ n（即 10）
    while (left < right) {
        ll mid = left + (right - left) / 2;  //因为都是1e9,用int可能会溢出
        if (mid / h == 0) {
            left = mid + 1;  //如果mid小于h往右走并跳到下一轮
            continue;
        }
        if ((mid / w) >= (n + (mid / h) - 1) / (mid / h)) { //直接用(mid/w)*(mid/h)会溢出，用数学等价转换
            right = mid;
        }else left = mid + 1;
    }
    cout << left << endl;
    return 0;
}