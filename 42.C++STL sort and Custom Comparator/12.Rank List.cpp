//又一场编程比赛结束了。你拿到了比赛的最终成绩表。表中包含以下数据：每支队伍显示两个数字——解决的问题数量和总罚时。然而，没有显示任何队伍的最终名次。
//你非常清楚两支队伍成绩比较的规则。假设队伍 a 解决了 pₐ 道题，总罚时为 tₐ；队伍 b 解决了 p_b 道题，总罚时为 t_b。如果满足以下条件之一，则队伍 a 的最终排名高于队伍 b：
//解决的题目数更多（pₐ > p_b）；
//解决的题目数相同，但总罚时更少（pₐ = p_b 且 tₐ < t_b）。
//换句话说，队伍 a 在最终成绩表中排名高于队伍 b，当且仅当 pₐ > p_b，或 pₐ = p_b 且 tₐ < t_b。
//如果多支队伍解决的题目数和总罚时都相同，则它们共享对应的名次。
//更正式地说，假设有 x 支队伍解决了相同数量的题目并具有相同的总罚时，另有 y 支队伍的成绩优于这组队伍，那么这组队伍的名次为 y+1, y+2, …, y+x。成绩比这组队伍差的队伍，其名次从 y+x+1 开始依次分配。
//你的任务是：统计给定列表中，有多少支队伍共享第 k 名。
//输入​
//第一行包含两个整数 n 和 k（1 ≤ k ≤ n ≤ 50）。
//接下来 n 行，每行描述一支队伍：第 i 行包含两个整数 pᵢ 和 tᵢ（1 ≤ pᵢ, tᵢ ≤ 50）—— 第 i 支队伍解决的问题数量和总罚时，数字之间用空格分隔。
//输出​
//仅一行，输出获得第 k 名的队伍数量。
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

void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> arr(n);
	map<pair<int, int>, int> mp;
	for (int i = 0; i < n; i++) {
		int p, t;
		cin >> p >> t;
		mp[{p, t}]++;
		arr[i] = {p, t};
	}
	sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int,int>& b){
		if (a.first != b.first) return a.first > b.first;
		return a.second < b.second;
	});
	auto res = arr[k - 1];
	cout << mp[res] << enl;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	solve();
    return 0;
}