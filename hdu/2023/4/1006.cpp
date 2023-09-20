#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--)  {
    int n;
    scanf("%d", &n);
    printf("%.9lf ", (double)(2 * n - 2) / n);
    if(n > 2) printf("2.000000000\n");
    else printf("1.000000000\n");
  }
  return 0;
}