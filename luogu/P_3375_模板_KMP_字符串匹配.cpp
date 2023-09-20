#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
char a[N], b[N];
int k[N];

void kmp() {
  int len_a = strlen(a + 1), len_b = strlen(b + 1);
  int j = 0;
  for(int i = 2; i <= len_b; i++) {
    while(j && b[j + 1] != b[i]) j = k[j];
    if(b[j + 1] == b[i]) j++;
    k[i] = j;
  }
  j = 0;
  for(int i = 1; i <= len_a; i++) {
    while(j && b[j + 1] != a[i]) j = k[j];
    if(b[j + 1] == a[i]) j++;
    if(j == len_b) cout << i - j + 1 << endl;
  }
  for(int i = 1; i <= len_b; i++) cout << k[i] << ' ';
  cout << endl;
}

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> a + 1 >> b + 1;
  kmp();
  return 0;
}