#include<bits/stdc++.h>
using namespace std;

const int N = 3e7 + 5;

char s1[N], s2[N];
int n, len[N];

void update() {
  s2[0] = s2[1] = '#';
  for(int i = 1; i <= n; i++) {
    s2[i << 1] = s1[i - 1];
    s2[i << 1 | 1] = '#';
  }
  n = 2 * n + 1;
}

void init() {
  scanf("%s", s1);
  n = strlen(s1);
  update();
}

void manacher() {
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

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  init(); 
  manacher();
  int ans = 0;
  for(int i = 1; i <= n; i++) 
    ans = max(ans, len[i] - 1);
  cout << ans << endl;
  return 0;
}