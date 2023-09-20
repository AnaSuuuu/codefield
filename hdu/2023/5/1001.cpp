#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e4 + 5;
struct Node {
  double x, y;
} ty[N], sh[N];
double Min(double x, double y) {
  return x < y ? x : y;
}
double Fabs(double x) {
  return x < 0 ? -x : x;
}
int main(){
  freopen("1001.in", "r", stdin);
  freopen("1001.out", "w", stdout);
  int m, n;
  scanf("%d%d", &m, &n);
  for(int i = 1; i <= m; i++) 
    scanf("%lf%lf", &ty[i].x, &ty[i].y);
  for(int i = 1; i <= n; i++) 
    scanf("%lf%lf", &sh[i].x, &sh[i].y);
  for(int i = 1; i <= n; i++) {
    double r = sqrt((ty[1].x - sh[i].x) * (ty[1].x - sh[i].x) + (ty[1].y - sh[i].y) * (ty[1].y - sh[i].y));
    for(int j = 2; j <= m; j++) 
      r = Min(r, sqrt((ty[j].x - sh[i].x) * (ty[j].x - sh[i].x) + (ty[j].y - sh[i].y) * (ty[j].y - sh[i].y)));
    for(int j = 1; j < m; j++) {
      double X1 = sh[i].x - ty[j].x, X2 = sh[i].x - ty[j + 1].x, X3 = ty[j + 1].x - ty[j].x;
      double Y1 = sh[i].y - ty[j].y, Y2 = sh[i].y - ty[j + 1].y, Y3 = ty[j + 1].y - ty[j].y;
      if(X1 * X3 + Y3 * Y1 <= 0 || X2 * (-X3) + (-Y3) * Y2 <= 0) continue;
      r = Min(r, Fabs(X1 * Y3 - Y1 * X3) / sqrt(X3 * X3 + Y3 * Y3));
    }
    printf("%.4lf\n", r);
  }
  return 0;
}