//给你一个数组，判断是否可以将数组分成两部分
//使得两数组的和相等
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
const char enl = '\n';

void solve() {
	vector<int> nums = {1, 2, 3, 5};
	int n = nums.size();
	bitset<10001> bs; //因为nums长度最高为200，值最大为100 所以是 200 * 100 / 2 目标值为10000
	int sum = 0;
	for (int i: nums) {
		sum += i;
	}
	bool flag = true;
	if (sum % 2 != 0) flag = false;
    bs[0] = 1;   //bs默认0可以取
	for (int i: nums)  {
		bs |= (bs << i); //如果当前能凑出 j，那么加上 x 后就能凑出 j + x
	}
	cout << bs[sum / 2] << enl;
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