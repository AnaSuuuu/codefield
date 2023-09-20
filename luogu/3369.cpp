#include<bits/stdc++.h>
using namespace std;
const ll N=1e5+5;
struct Treap{
  ll size_[N],l_[N],r_[N];
  ll val_[N],rnd_[N],cnt_[N];
  ll sz,rt,ans;
  void pushup(ll rt){
    size_[rt]=size_[l_[rt]]+size_[r_[rt]]+cnt_[rt];
  }
  void lrotate(ll &rt){
    ll tmp=r_[rt];
    r_[rt]=l_[tmp];
    l_[tmp]=rt;
    size_[tmp]=size_[rt];
    pushup(rt);
    rt=tmp;
  }
  void rrotate(ll &rt){
    ll tmp=l_[rt];
    l_[rt]=r_[tmp];
    r_[tmp]=rt;
    size_[tmp]=size_[rt];
    pushup(rt);
    rt=tmp;
  }
  void _insert(ll &rt,ll val){
    if(!rt){
      sz++;
      rt=sz;
      size_[rt]=1;
      val_[rt]=val;
      cnt_[rt]=1;
      rnd_[rt]=rand();
      return ;
    }
    size_[rt]++;
    if(val_[rt]==val){
      cnt_[rt]++;
    }
    else if(val_[rt]<val){
      _insert(r_[rt],val);
      if(rnd_[r_[rt]]<rnd_[rt])lrotate(rt);
    }
    else {
      _insert(l_[rt],val);
      if(rnd_[l_[rt]]<rnd_[rt])rrotate(rt);
    }
  }
  bool _del(ll &rt,ll val){
    if(!rt)return false;
    if(val_[rt]==val){
      if(cnt_[rt]>1){
        size_[rt]--;
        cnt_[rt]--;
        return true;
      }
      if(l_[rt]==0||r_[rt]==0){
        rt=l_[rt]+r_[rt];
        return true;
      }
      else if(rnd_[l_[rt]]<rnd_[r_[rt]]){
        rrotate(rt);
        return _del(rt,val);
      }
        else {
          lrotate(rt);
          return _del(rt,val);
        }
    }
    else if(val_[rt]<val){
      bool ok=_del(r_[rt],val);
      if(ok)size_[rt]--;
      return ok;
    }
      else {
        bool ok=_del(l_[rt],val);
        if(ok)size_[rt]--;
        return ok;
      }
  }
  ll _queryrank(ll &rt,ll val){
    if(!rt)return 0;
    if(val_[rt]==val)
      return size_[l_[rt]]+1;
    else if(val_[rt]<val)
            return size_[l_[rt]]+cnt_[rt]+_queryrank(r_[rt],val);
          else return _queryrank(l_[rt],val);
  }
  ll _querynum(ll &rt,ll val){
    if(!rt)return 0;
    if(size_[l_[rt]]+1<=val&&val<=size_[l_[rt]]+cnt_[rt])
      return val_[rt];
    else if(size_[l_[rt]]>=val)
            return _querynum(l_[rt],val);
          else return  _querynum(r_[rt],val-size_[l_[rt]]-cnt_[rt]);
  }
  void _querypre(ll &rt,ll val){
  	if(!rt)return ; 
    if(val_[rt]<val){
      ans=val_[rt];
      _querypre(r_[rt],val);
    }
    else _querypre(l_[rt],val);
  }
  void _querysup(ll &rt,ll val){
  	if(!rt)return ;
    if(val_[rt]>val){
      ans=val_[rt];
      _querysup(l_[rt],val);
    }
    else _querysup(r_[rt],val);
  }
}T;

ll main(){
  freopen("3369.in","r",stdin);
  freopen("3369.out","w",stdout);
  srand(123);
  ll n;
  scanf("%d",&n);
  while(n--){
    ll op,x;
    scanf("%d%d",&op,&x);
    switch(op){
      case 1:{
        T._insert(T.rt,x);
        break;
      }      
      case 2:{
        T._del(T.rt,x);
        break;
      }      
      case 3:{
        prllf("%d\n",T._queryrank(T.rt,x));
        break;
      }      
      case 4:{
        prllf("%d\n",T._querynum(T.rt,x));
        break;
      }      
      case 5:{
        T._querypre(T.rt,x);
        prllf("%d\n",T.ans);
        break;
      }      
      case 6:{
        T._querysup(T.rt,x);
        prllf("%d\n",T.ans);
        break;
      }      
    }
  }
  return 0;
}
