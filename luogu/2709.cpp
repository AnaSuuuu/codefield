#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e4+5;
ll a[N],cnt[N],num[N];
struct Node{
  int l,r,id;
}Q[N];
ll ans[N],now;
bool cmp(Node x,Node y){
  return (num[x.l]^num[y.l])?num[x.l]<num[y.l]:(num[x.l]&1)?x.r<y.r:x.r>y.r;
}
void add(int pos){
  now-=cnt[a[pos]]*cnt[a[pos]];
  cnt[a[pos]]++;
  now+=cnt[a[pos]]*cnt[a[pos]];
}
void del(int pos){
  now-=cnt[a[pos]]*cnt[a[pos]];
  cnt[a[pos]]--;
  now+=cnt[a[pos]]*cnt[a[pos]];
}
int main(){
  freopen("2709.in","r",stdin);
  freopen("2709.out","w",stdout);
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int size=sqrt(n);
  int block_num=ceil((double)n/size);
  for(int i=1;i<=size;i++)
    for(int j=(i-1)*size+1;j<=i*size;j++)
      num[j]=i;
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=1;i<=m;i++){
    scanf("%d%d",&Q[i].l,&Q[i].r);
    Q[i].id=i;
  }
  sort(Q+1,Q+1+m,cmp);
  int l=1,r=0;
  for(int i=1;i<=m;i++){
    while(l<Q[i].l)del(l++);
    while(l>Q[i].l)add(--l);
    while(r<Q[i].r)add(++r);
    while(r>Q[i].r)del(r--);
    ans[Q[i].id]=now;
  }
  for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
  return 0;
}