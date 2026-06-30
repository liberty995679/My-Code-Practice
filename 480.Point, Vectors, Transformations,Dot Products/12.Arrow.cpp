//输入px,py,vx,vy,a,b,c,d
//以逆时针的方向输出等腰三角形和矩形的点的坐标
//a是三角形的底边，b是三角形的高
//c是矩形的长，d是矩形的宽
//从三角形箭头开始
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
using namespace std;
using ll = long long;
vector<pair<double, double>> ans;
const double pi = acos(-1);
double calculate(double x, double y) {
   double dis = sqrt((x * x) + y * y);
   return dis;
}

double danweivector(double x, double mod) {
   return x / mod;
}

pair<double, double> dingdian(double px, double py, double vx, double vy, double b ){
   double dx = danweivector(vx, calculate(vx, vy));
   double dy = danweivector(vy, calculate(vx, vy)); //计算单位向量
   double x1 = px + dx * b;
   double y1 = py + dy * b;
   return {x1, y1};
}

pair<double, double> dingdian2(double px, double py, double vx, double vy, double b){
   double dx = danweivector(vx, calculate(vx, vy));
   double dy = danweivector(vy, calculate(vx, vy)); //计算单位向量
   double x1 = px + -dy * b;
   double y1 = py + dx * b;
   return {x1, y1};
}

pair<double, double> dingdian3(double px, double py, double vx, double vy, double b){
   double dx = danweivector(vx, calculate(vx, vy));
   double dy = danweivector(vy, calculate(vx, vy)); //计算单位向量
   double x1 = px + -dy * b;  //逆时针垂直
   double y1 = py + dx * b;
   return {x1, y1};
}

pair<double, double> dingdian4(double px, double py, double vx, double vy, double b){
   double dx = danweivector(vx, calculate(vx, vy));
   double dy = danweivector(vy, calculate(vx, vy)); //计算单位向量
   double x1 = px + -dx * b;
   double y1 = py + -dy * b;
   return {x1, y1};
}

pair<double, double> dingdian7(double px, double py, double vx, double vy, double b){
   double dx = danweivector(vx, calculate(vx, vy));
   double dy = danweivector(vy, calculate(vx, vy)); //计算单位向量
   double x1 = px + dy * b;   //顺时针,垂直
   double y1 = py + -dx * b;
   return {x1, y1};
}

pair<double, double> dingdian6(double px, double py, double vx, double vy, double b){
   double dx = danweivector(vx, calculate(vx, vy));
   double dy = danweivector(vy, calculate(vx, vy)); //计算单位向量
   double x1 = px + dy * b;   //顺时针,垂直
   double y1 = py + -dx * b;
   return {x1, y1};
}

pair<double, double> dingdian5(double px, double py, double vx, double vy, double b){
   double dx = danweivector(vx, calculate(vx, vy));
   double dy = danweivector(vy, calculate(vx, vy)); //计算单位向量
   double x1 = px + -dx * b;   //相反
   double y1 = py + -dy * b;
   return {x1, y1};
}

void solve() {
   double px,py,vx,vy,a,b,c,d;
   cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
   auto topxy = dingdian(px, py, vx, vy, b);
   ans.push_back(topxy);
   auto twoxy = dingdian2(px, py, vx, vy, a / 2);
   double x1 = topxy.first; double y1 = topxy.second;
   double x2 = twoxy.first; double y2 = twoxy.second;
   auto thirdxy = dingdian3(px, py, vx, vy, c / 2);
   double x3 = thirdxy.first; double y3 = thirdxy.second;
   auto fourthxy = dingdian4(x3, y3, vx, vy, d);
   auto sevenxy = dingdian7(px, py, vx, vy, a / 2);
   auto sixxy = dingdian6(px, py, vx, vy, c / 2);
   double x6 = sixxy.first; double y6 = sixxy.second;
   auto fivexy = dingdian5(x6, y6, vx, vy, d);
   cout << fixed << setprecision(9);
   cout << x1 << ' ' << y1 << endl;
   cout << x2 << " " << y2 << endl;
   cout << x3 << ' ' << y3 << endl;
   cout << fourthxy.first << ' ' << fourthxy.second << endl;
   cout << fivexy.first << ' ' << fivexy.second << endl;
   cout << sixxy.first << ' ' << sixxy.second << endl;
   cout << sevenxy.first << ' ' << sevenxy.second << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   solve();
   return 0;
}