#include<bits/stdc++.h>
#define ull long long
using namespace std;
const int N=1e6+5;
struct L{
  ull l,r,op,len;
}l0[N<<2];
struct Line{
  ull x1,x2,y,c;
  bool operator <(const Line &x) const {
    return y<x.y;
  }
}ll[N<<1];
ull tot;
ull re[N],node[N<<1];
void build(ull rt,ull l,ull r){//这里的线段树维护的是线段，不是点，边的代号是1~tot-1
  l0[rt].op=0;
  l0[rt].len=0;
  l0[rt].l=l;
  l0[rt].r=r;
  if(l==r)return ;
  ull mid=(l+r)/2;
  build(rt<<1,l,mid);
  build(rt<<1|1,mid+1,r);
}
void pushup(ull rt){
  if(l0[rt].op){
    l0[rt].len=node[l0[rt].r+1]-node[l0[rt].l];
  }
  else l0[rt].len=l0[rt<<1].len+l0[rt<<1|1].len;
}
void update(ull rt,ull l,ull r,ull op){
  ull L=node[l0[rt].l],R=node[l0[rt].r+1];
  if(L>=l&&R<=r){
    l0[rt].op+=op;
    pushup(rt);
    return ;
  }
  if(node[l0[rt<<1].r+1]>l)update(rt<<1,l,r,op);
  if(node[l0[rt<<1|1].l]<r)update(rt<<1|1,l,r,op);
  pushup(rt);
}

int main(){
  freopen("5490.in","r",stdin);
  freopen("5490.out","w",stdout);
  ull n;
  scanf("%lld",&n);
  for(ull i=1;i<=n;i++){
    ull x,y,X,Y;
    scanf("%lld%lld%lld%lld",&x,&y,&X,&Y);
    ll[i*2-1]=(Line){x,X,y,1};
    ll[i*2]=(Line){x,X,Y,-1};
    node[i*2-1]=x;
    node[i*2]=X;
  }
  sort(node+1,node+1+(n<<1));
  sort(ll+1,ll+1+(n<<1));
  tot=unique(node+1,node+1+(n<<1))-node-1;
  build(1,1,tot-1);
  ull ans=0;
  for(ull i=1;i<(n<<1);i++){
    update(1,ll[i].x1,ll[i].x2,ll[i].c);
    ans+=l0[1].len*(ll[i+1].y-ll[i].y);
  }
  printf("%lld\n",ans);
  return 0;
}