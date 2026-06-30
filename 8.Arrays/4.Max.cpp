//找出数组中的最大值
#include <iostream>

using namespace std;

const int N = 1e3 + 5;

int main() {
    int n;
    cin >> n;
    int max = 0;
    int nums[N] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] > max) max = nums[i];
    }
    cout << max << endl;
    return 0;
}