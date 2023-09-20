#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 6;
struct Node{
  ll p, d;
}s[N];
priority_queue<int, vector<int>, greater<int> > q;
bool cmp(Node x, Node y){
  return x.d < y.d;
}
int main() {
  freopen("2949.in", "r", stdin);
  freopen("2949.out", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d%d", &s[i].d, &s[i].p);
  }
  sort(s + 1, s + 1 + n, cmp);
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    if(s[i].d <= q.size() && s[i].p > q.top()){
      ans -= q.top();
      q.pop();
      q.push(s[i].p);
      ans += s[i].p;
    }
    else if(s[i].d > q.size()){
      ans += s[i].p;
      q.push(s[i].p);
    }
  }
  cout << ans << endl;
  return 0;
}