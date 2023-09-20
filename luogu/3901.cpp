#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],num[N];
struct Node{
  int l,r,id;
}Q[N];
int ans[N],now,cnt[N];
void in(int &x){
  x=0;
  int f=1;
  char c=getchar();
  while(c>'9'||c<'0'){
    if(c=='-')f=-1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+c-'0';
    c=getchar();
  }
  x*=f;
}
bool cmp(Node x,Node y){
  return (num[x.l]^num[y.l])?num[x.l]<num[y.l]:(num[x.l]&1)?x.r<y.r:x.r>y.r;
}
void add(int pos){
  if(!cnt[a[pos]])now++;
  cnt[a[pos]]++;
}
void del(int pos){
  cnt[a[pos]]--;
  if(!cnt[a[pos]])now--;
}
int main(){
  freopen("3901.in","r",stdin);
  freopen("3901.out","w",stdout);
  int n,q;
  in(n);in(q);
  int size=sqrt(n);
  int block_num=ceil((double)n/size);
  for(int i=1;i<=size;i++)
    for(int j=(i-1)*size+1;j<=i*size;j++)
      num[j]=i;
  for(int i=1;i<=n;i++)in(a[i]);
  for(int i=1;i<=q;i++)in(Q[i].l),in(Q[i].r),Q[i].id=i;
  sort(Q+1,Q+1+q,cmp);
  int l=1,r=0;
  for(int i=1;i<=q;i++){
    while(l<Q[i].l)del(l++);
    while(l>Q[i].l)add(--l);
    while(r<Q[i].r)add(++r);
    while(r>Q[i].r)del(r--);
    if(now==Q[i].r-Q[i].l+1)ans[Q[i].id]=1;
    else ans[Q[i].id]=0;
  }
  for(int i=1;i<=q;i++)
    printf("%s\n",ans[i]?"Yes":"No");
  return 0;
}