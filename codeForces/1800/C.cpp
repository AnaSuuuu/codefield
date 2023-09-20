#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
inline void in(int &x){
  x=0;
  char c=getchar();
  ll f=1;
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
int s[N];
priority_queue<int> q;
int main(){
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  int t;
  in(t);
  while(t--){
    int n;
    ll ans=0;
    in(n);
    for(int i=1;i<=n;i++)in(s[i]);
    while(q.size()){
    	q.pop();
	}
    for(int i=1;i<=n;i++){
    //	cout<<s[i]<<endl;
      if(s[i]>0)q.push(s[i]);
      else {
      	if(q.size()){
      		//puts("AAA");
      		//cout<<q.top()<<endl;
			ans+=q.top();
        	q.pop();
		  }
      }
    }
    printf("%lld\n",ans);
  }
  return 0;
}
