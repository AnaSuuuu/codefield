#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Node {
  int num, id;
}a[N], b[N];
int ans[N];
bool cmp1(Node x, Node y) {
  return x.num < y.num;
}
bool cmp2(Node x, Node y) {
  return x.id < y.id;
}
int main() {
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i].num), a[i].id = i;
    for(int i = 1; i <= n; i++) scanf("%d", &b[i].num), b[i].id = i;
    sort(a + 1, a + 1 + n, cmp1);
    sort(b + 1, b + 1 + n, cmp1);
    for(int i = 1; i <= n; i++) ans[a[i].id] = b[i].id;
    sort(b + 1, b + 1 + n, cmp2);
    for(int i = 1; i <= n; i++) printf("%d ", b[ans[i]]);
    puts("");
  }
  return 0;
}