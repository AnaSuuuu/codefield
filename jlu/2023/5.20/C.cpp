#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> e[N];
char s[10];
int dis[N];
struct Node {
  int dis, id;
}T[N], C[N], D[N];
int tot1, tot2, tot3;
void dfs(int u, int f) {
  dis[u] = dis[f] + 1;
  for(int v: e[u]) {
    if(v == f) continue;
    dfs(v, u);
  }
  return ;
}
bool cmp(Node x, Node y){
  return x.dis < y.dis;
}
int main() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int n;
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d %s\n", &u, &v, s + 1);
    e[u].emplace_back(v);
    e[v].emplace_back(u);
    //cout << s[1] << endl;
    if(s[1] == '-') continue;
    if(s[1] == 'T') T[++tot1].id = u;
    if(s[1] == 'D') D[++tot2].id = u;
    if(s[1] == 'C') C[++tot3].id = u;
  }
  //cout << tot1 << ' ' << tot2 << ' ' << tot3 << endl;
  if(tot1 % 2) {
    puts("NO");
    return 0;
  }
  if(tot2 != tot3) {
    puts("NO");
    return 0;
  }
  dfs(1, 0);
  for(int i = 1; i <= tot1; i++) T[i].dis = dis[T[i].id];
  for(int i = 1; i <= tot2; i++) D[i].dis = dis[D[i].id];
  for(int i = 1; i <= tot3; i++) C[i].dis = dis[C[i].id];
  /*for(int i = 1; i <= n; i++) {
    cout << dis[i] << ' ';
  }
  cout << endl;*/
  sort(T + 1, T + 1 + tot1, cmp);
  sort(D + 1, D + 1 + tot2, cmp);
  sort(C + 1, C + 1 + tot3, cmp);
  for(int i = 2; i <= tot1; i +=2) {
    if(T[i].dis != T[i - 1].dis) {
      puts("NO");
      return 0;
    }
  }
  for(int i = 1; i <= tot2; i++) {
    if(D[i].dis >= C[i].dis) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for(int i = 2; i <= tot1; i +=2) {
    printf("%d %d\n", T[i - 1].id, T[i].id);
  }
  for(int i = 1; i <= tot2; i++) {
    printf("%d %d\n", C[i].id, D[i].id);
  }
  return 0;
}
