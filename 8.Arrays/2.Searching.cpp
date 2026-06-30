//在数组里找数字，找到则输出它第一次出现的位置，否则输出-1
#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int main() {
    int n, x;
    cin >> n;
    int nums[N] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cin >> x;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == x) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}