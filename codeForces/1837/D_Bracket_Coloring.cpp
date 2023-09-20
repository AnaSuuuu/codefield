#include<bits/stdc++.h>

const int N = 2e5 + 5;
int col[N];

void solve() {
  int n;
  std::cin >> n;
  for(int i = 0; i <= n; i++) col[i] = 0;
  std::stack<int> q;
  std::string s;
  std::cin >> s;
  int tmp = 0, ans = 0, ok = 1;
  int cnt1 = 0, cnt2 = 0;
  
  for(int i = 0; i < n; i++) {
    if(s[i] == '(') tmp++;
    else tmp--;
  }
  if(tmp) {
    std::cout << "-1\n";
    return ;
  }

  tmp = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '(') {
      tmp++;
      q.push(i);
    }
    else {
      if(tmp > 0) {
        tmp--;
        ans += ok; ok = 0;
        cnt1 += 2;
        q.pop();
      }
    }
  }
  while(q.size()) q.pop();
  if(cnt1 == n) {
    std::cout << "1\n";
    for(int i = 0; i < n; i++) 
      std::cout << 1 << " \n"[i == n - 1];
    return ;
  }

  tmp = 0, ok = 1;
  for(int i = n - 1; i >= 0; i--) {
    if(col[i]) continue;
    //std::cout << i << "\n";
    if(s[i] == '(') {
      tmp++;
      q.push(i);
    }
    else {
      if(tmp > 0) {
        tmp--;
        ans += ok; ok = 0;
        cnt2 += 2;
        q.pop();
      }
    }
  }
  while(q.size()) q.pop();
  if(cnt2 == n) {
    std::cout << "1\n";
    for(int i = 0; i < n; i++) 
      std::cout << 1 << " \n"[i == n - 1];
    return ;
  }

  tmp = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '(') {
      tmp++;
      q.push(i);
    }
    else {
      if(tmp > 0) {
        tmp--;
        ans += ok; ok = 0;
        col[i] = 1;
        col[q.top()] = 1;
        q.pop();
      }
    }
  }
  while(q.size()) q.pop();
  tmp = 0, ok = 1;
  for(int i = n - 1; i >= 0; i--) {
    if(col[i]) continue;
    if(s[i] == '(') {
      tmp++;
      q.push(i);
    }
    else {
      if(tmp > 0) {
        tmp--;
        ans += ok; ok = 0;
        col[i] = 2;
        col[q.top()] = 2;
        q.pop();
      }
    }
  }
  std::cout << 2 << "\n";
  for(int i = 0; i < n; i++) 
    std::cout << col[i] << " \n"[i == n - 1];
  return ;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}