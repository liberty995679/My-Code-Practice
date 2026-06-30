//找出数组中的最小值和位置
#include <iostream>

using namespace std;

const int N = 1003;

int main() {
    int n;
    cin >> n;
    int pos = 0;
    int nums[N] = {0};
    int min = 1e5 + 1;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] < min) {
            min = nums[i];
            pos = i;
        }
    }
    cout << min << " " << pos + 1 << endl;
    return 0;
}