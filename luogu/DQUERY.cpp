#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N=3e5+5;
const int M=1e6+5;
int a[N],num[N],cnt[M],ans;
int rep[N];
struct Node{
  int l,r,id;
}s[N];
inline void in(int &x){
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
  if(!cnt[a[pos]])ans++;
  cnt[a[pos]]++;
}
void del(int pos){
  cnt[a[pos]]--;
  if(!cnt[a[pos]])ans--;
}
int main(){
  freopen("DQUERY.in","r",stdin);
  freopen("DQUERY.out","w",stdout);
  int n;
  in(n);
  int size=sqrt(n);
  int block_num=ceil((double)n/size);
  for(int i=1;i<=block_num;i++){
    for(int j=(i-1)*size+1;j<=i*size;j++)
      num[j]=i;
  }
  for(int i=1;i<=n;i++)in(a[i]);
  int q;
  scanf("%d",&q);
  for(int i=1;i<=q;i++)in(s[i].l),in(s[i].r),s[i].id=i;
  sort(s+1,s+1+q,cmp);
  int l=1,r=0;
  for(int i=1;i<=q;i++){
    //cout<<s[i].l<<' '<<s[i].r<<endl;
    while(l<s[i].l) del(l++);
    //cout<<l<<' '<<ans<<endl;
    while(l>s[i].l) add(--l);
    //cout<<l<<' '<<ans<<endl;
    while(r<s[i].r) add(++r);
    //cout<<ans<<endl;
    while(r>s[i].r) del(r--);
    //cout<<ans<<endl;
    rep[s[i].id]=ans;
  }
  for(int i=1;i<=q;i++)cout<<rep[i]<<endl;
  return 0;
}