//你被给定 n 个数组 a₁, a₂, …, aₙ，每个数组的长度都是 2，即 aᵢ = [aᵢ,₁, aᵢ,₂]。
//你需要将这些数组合并成一个长度为 2n 的数组，使得结果数组中的逆序对数量尽可能少。
//注意，你不需要计算具体的逆序对数量，只需要构造出这样的一个数组。
//更正式地说，你需要选择一个长度为 n 的排列 p，使得数组
//b = [a{p₁,₁}, a{p₁,₂}, a{p₂,₁}, a{p₂,₂}, …, a{pₙ,₁}, a{pₙ,₂}]
//中的逆序对数量最少。
//定义：一个数组 c 的逆序对数量，是指满足 i < j 且 cᵢ > cⱼ 的下标对 (i, j) 的数量。
//定义：长度为 n 的排列，是一个由 1 到 n 的 n 个不同整数按任意顺序排列组成的数组。
//例如，[2, 3, 1, 5, 4] 是一个排列，但 [1, 2, 2] 不是（因为 2 出现了两次），[1, 3, 4] 也不是（n=3 但出现了 4）。
//输入​
//每个测试包含多个测试用例。
//第一行包含一个整数 t（1 ≤ t ≤ 10⁴）—— 测试用例的数量。
//每个测试用例的描述如下：
//第一行包含一个整数 n（1 ≤ n ≤ 10⁵）—— 数组的数量。
//接下来的 n 行，每行包含两个整数 aᵢ,₁ 和 aᵢ,₂（1 ≤ aᵢ,ⱼ ≤ 10⁹）—— 第 i 个数组的元素。
//保证所有测试用例的 n 之和不超过 10⁵。
//输出​
//对于每个测试用例，输出 2n 个整数—— 你得到的合并后的数组。
//如果有多种解，输出任意一种即可。
#include <iostream>
#include <algorithm>
#include <sstream>
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

struct nums{
	ll val;
	int pos;
};

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	vector<nums> res(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		res[i] = {arr[i].first + arr[i].second, i};
	}
	vector<int> idx(n);
	sort(res.begin(), res.end(), [](const nums& a, const nums& b){
		return a.val < b.val;   //相加的值越小在前面
	});
	for (int i = 0; i < n; i++) {
		idx[i] = res[i].pos;
	}
	bool flag = false;
	for (int i = 0; i < n; i++) {
		int j = idx[i];
		if (flag) cout << ' ';
		cout << arr[j].first << ' ' << arr[j].second;
		flag = true;
	}cout << enl;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) solve();
    return 0;
}