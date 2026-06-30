//根据输入的坐标判断它的位置
//Q1,Q2,Q3,Q4,Origem, Eixo x, Eixo Y
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

string solve(double x, double y) {
    if (x == 0 && y == 0) return "Origem";
    if (x == 0) return "Eixo Y";
    if (y == 0) return "Eixo X";
    if (x > 0 && y > 0) return "Q1";
    else if (x > 0 && y < 0) return "Q4";
    else if (x < 0 && y > 0) return "Q2";
    return "Q3";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double x, y;
    cin >> x >> y;
    cout << solve(x, y) << endl;
    return 0;
}