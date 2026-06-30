//当n大于2时，输出5的n次方的最后两位数
#include <iostream>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    cout << 25 << endl;  //无论n是多少,最后两位数都是25
    return 0;
}