#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
int c[N];
int s[N], n, m;
int lowbit(int x){ return x & (-x); }
void add(int x){
  for(int i = x; i <= m; i += lowbit(i)) c[i]++;
  return ;
}
int query(int x){
  int num = 0;
  for(; x; x -=lowbit(x)) num += c[x];
  return num;
}
int main(){
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while(t--){
    int tot = 0, kdl = 0;
    int num1 = 0, num2 = 0;
    int lm = 0x3f3f3f3f, rm = -0x3f3f3f3f;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) c[i] = 0;
    for(int i = 1; i <= m; i++) vis[i] = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%d", &s[i]);
      if(s[i] > 0){
        lm = min(lm, s[i]);
        rm = max(rm, s[i]);
        add(s[i]);
        if(vis[s[i]] == 0) tot++, kdl++;
        vis[s[i]] = 1;
      }
      else {
        if(s[i] == -1) num1++;
        else num2++;
      }
    }
    //sort(s + 1, s + 1 + n);
    int gap;
    if(tot != 0) {
      gap = query(rm) - query(lm - 1);
      gap = (rm - lm + 1) - gap;
    }
    else {
      gap = 0;
      cout << max(num1, num2) << endl;
      continue;
    }
    int Num1 = num1, Num2 = num2;
    //cout << gap << endl;
    
    //cout << gap << endl;
    //cout << num1 << ' ' << num2 << endl;
    /*if(num2 >= gap) {
      num2 -= gap;
      tot += gap;
      tot += min(m - rm, num2);
      tot += min(lm - 1, num1);
    }
    else {
      gap -= num2;
      tot += num2;
      if(num1 >= gap) {
        num1 -= gap;
        tot += gap;
        tot += min(lm - 1, num1);
      }
      else tot += num1;
    }*/
    if(num2 >= m - rm) {
      num2 -= (m - rm);
      tot += (m - rm);
    }
    else {
      tot += num2;
      num2 = 0;
    }
    if(num1 >= lm - 1) {
      num1 -= (lm - 1);
      tot += (lm - 1);
    }
    else {
      tot += num1;
      num1 = 0;
    }
    tot += min(num1 + num2, gap);
    //cout << tot << endl;
    cout << max(tot, max(min(Num1 + kdl, m), min(Num2 + kdl, m))) << endl;
  }
  return 0;
}