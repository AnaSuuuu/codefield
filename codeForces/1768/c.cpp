#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node{
  int id,num1,num2;
}s[N];
int vis[N],Vis[N];
int used[N];
void in(int &x){
  x=0;
  int f=1;
  char c=getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<1)+(x<<3)+(c-'0');
    c=getchar();
  }
  x*=f;
}
bool cmp1(Node x,Node y){
  return x.num1<y.num1;
}
bool cmp2(Node x,Node y){
  return x.id<y.id;
}
int main(){
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  int t;
  in(t);
  while(t--){
    int n,ok=0;
    in(n);
    //cout<<n<<endl;
    memset(vis,0,sizeof(vis));
    memset(Vis,0,sizeof(Vis));
    memset(used,0,sizeof(used));
    for(int i=1;i<=n;i++){
      in(s[i].num1);
      vis[s[i].num1]=1;
      used[s[i].num1]++;
      s[i].id=i;
      s[i].num2=0;
    }
    sort(s+1,s+1+n,cmp1);
    int kdl=1;
    for(int i=1;i<=n;i++){
      while(vis[kdl]==1&&kdl<=n)kdl++;
      if(Vis[s[i].num1]){
        if(kdl>s[i].num1){
          puts("NO");
          ok=1;
          break;
        }
        s[i].num2=s[i].num1;
        s[i].num1=kdl;
        vis[kdl]=1;
        used[kdl]++;
      }
      Vis[s[i].num1]=1;
    }
    if(ok)continue;
    kdl=1;
    for(int i=1;i<=n;i++){
      while(used[kdl]>=2&&kdl<=n)kdl++;
      if(s[i].num2==0){
        if(kdl>s[i].num1){
          puts("NO");
          ok=1;
          break;
        }
        s[i].num2=kdl;
        used[kdl]++;
      }
    }
    if(ok)continue;
    memset(vis,0,sizeof(vis));
    int num=n;;
    for(int i=1;i<=n;i++){
      if(vis[s[i].num1]){
        puts("NO");
        ok=1;
        break;
      }
      vis[s[i].num1]=1;
    }
    if(ok)continue;
    //puts("AAA");
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
      if(vis[s[i].num2]){
        puts("NO");
        ok=1;
        break;
      }
      vis[s[i].num2]=1;
    }
    if(ok)continue;
    sort(s+1,s+1+n,cmp2);
    if(ok)continue;
    puts("YES");
    for(int i=1;i<=n;i++)printf("%d ",s[i].num1);
    cout<<endl;
    for(int i=1;i<=n;i++)printf("%d ",s[i].num2);
    cout<<endl;/**/
  }
  return 0;
}