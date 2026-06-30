//基数排序
//输入
//输入的第一行将包含一个整数 N，表示序列的大小。
//第二行将包含 N 个用空格分隔的随机整数。
//输出
//打印给定序列中 N 个数字的排序序列。
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
#include <bitset>
using namespace std;
using ll = long long;
const char enl = '\n';

// 获取数字的第 d 位（从右往左，d=0 表示个位）
int getDigit(int num, int d) {
    for (int i = 0; i < d; i++) {
        num /= 10;
    }
    return num % 10;
}

// 基数排序（LSD）
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    // 找到最大值，确定需要多少位
    int maxVal = *max_element(arr.begin(), arr.end());
    int maxDigits = 0;
    while (maxVal > 0) {
        maxDigits++;
        maxVal /= 10;
    }
    // 对每一位进行计数排序
    for (int d = 0; d < maxDigits; d++) {
        // 10 个桶（0-9）
        vector<vector<int>> buckets(10);
        // 根据当前位放入对应桶
        for (int num : arr) {
            int digit = getDigit(num, d);
            buckets[digit].push_back(num);
        }
        // 按顺序收集回原数组
        int idx = 0;
        for (int i = 0; i < 10; i++) {
            for (int num : buckets[i]) {
                arr[idx++] = num;
            }
        }
    }
}


void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	radixSort(arr);
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << ' ';
		cout << arr[i];
	}cout << enl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}