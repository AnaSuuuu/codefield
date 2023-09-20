#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 5e5 + 5;
char s1[N], s2[N];
ll len[N], n, ans[N];

bool judge() {
  n = strlen(s1 + 1);
  for(int i = 2; i <= n; i++) if(s1[i] != s1[i - 1]) return false;
  return true; 
}
void work(int x) {
  ll Ans = x - 1, tmp;
  if(Ans % 2 == 0) tmp = 2;
  else tmp = 1;
  ll kdl = (Ans + 1) / 2;
  printf("%lld ", 1ll * (Ans + tmp) * kdl / 2);
  return ;
}


void update() {
  s2[0] = s2[1] = '#';
  for(int i = 1; i <= n; i++) {
    s2[i << 1] = s1[i];
    s2[i << 1 | 1] = '#';
  }
  n = 2 * n + 1;
}

void manacher() {
  update();
  int maxr = 0, mid = 0;
  for(int i = 1; i <= n; i++) {
    if(i < maxr) len[i] = min(len[(mid << 1) - i], len[mid] + mid - i);
    else len[i] = 1;
    while(i + len[i] <= n &&  i - len[i] > 0 && s2[i + len[i]] == s2[i - len[i]]) len[i]++;
    if(len[i] + i > maxr) {
      maxr = len[i] + i;
      mid = i; 
    } 
  }
}


void solve() {
  scanf("%s", s1 + 1);
  if(judge()) {
    for(int i = 1; i <= n; i++) work(i);
    puts("");
    return ;
  }
  n = strlen(s1 + 1);
  manacher();
  for(int i = 1; i <= n; i++) ans[i] = 0;
  for(int i = 1; i <= n; i += 2) {
    if(len[i] == 1) continue;
    for(int j = 1; j <= len[i] - 1; j += 2) {
      int L = i - j, R = i + j;
      int mid1 = (L + i - 1) >> 1, mid2 = (R + i + 1) >> 1;
      if(len[mid1] * 2 - 1 >= (i - L) && len[mid2] * 2 - 1 >= (R - i)) ans[R / 2]++;
    }
  }
  for(int i = 2; i <= n; i += 2) printf("%d ", ans[i / 2]), ans[i / 2 + 1] += ans[i / 2];
  cout << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  return 0;
}