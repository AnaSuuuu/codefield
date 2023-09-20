#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e6 + 5;
int len[N], n;
string s1, s2;

void update() {
  s2[0] = s2[1] = '#';
  for(int i = 1; i <= n; i++) {
    s2[i << 1] = s1[i - 1];
    s2[i << 1 | 1] = '#';
  }
  n = 2 * n + 1;
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

void solve() {
  cin >> s1;
  n = s1.size();
  manacher();
  int j = 0;
  for(int i = 1; i <= n; i++) {
    for(int k = j + 1; k <= i + len[i]; k++) 
  }
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    solve();
  } 
  return 0;
}