#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cur1;
const int N = 4e4 + 5;
//int qq[N];
vector<int> q;
struct Node{
  ll id1, id2, num;
};
Node kdl[N];
bool cur2;
bool cmp(Node x, Node y){
  return x.num < y.num;
}
int main(){
  freopen("5569.in", "r", stdin);
  freopen("5569.out", "w", stdout);
  ll n, ans = 0;
  scanf("%d", &n);
  int x;
  q.clear();
  for(int i = 1; i <= n; i++) scanf("%d", &x), q.emplace_back(x);
  for(int i = 1; i < n; i++){
    int tmp = 0;
    int tot = 0;
    for(int j: q){
      if(tmp == 0) {
        tmp = j;
        continue;
      }
      kdl[++tot].num = j + tmp;
      kdl[tot].id1 = tot - 1, kdl[tot].id2 = tot;
      tmp = j;/**/
    }
    //cout << tot << ' ';
    sort(kdl + 1, kdl + 1 + tot, cmp);
    ans += kdl[1].num;
    //cout << q.begin() << ' ' << q.end() << endl;
    //cout << kdl[1].num << endl;
    q[kdl[1].id1] = kdl[1].num;
    q.erase(q.begin() + kdl[1].id2);
    //for(int j: q) cout << j << ' ';
    //cout << endl;
  }
  //puts("AAA");
  //cout << q.size() << endl;
  //cout << q.front() << endl;
  cout << ans << endl;
  printf("占用%dmb", (&cur2 - &cur1) >> 20);
  return 0;
}