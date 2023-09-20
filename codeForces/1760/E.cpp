#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int b[N];
struct Node{
  long long zero,one;
}_count[N];
int main(){
  //freopen("E.in","r",stdin);
  //freopen("E.out","w",stdout);
  int t;
  cin >> t;
  while(t--){
    int n;
    long long  ans1=0, ans2=0;
    cin >> n;
    for(int i=1;i<=n;i++){
      cin >> b[i];
      _count[i].one=_count[i].zero=0;
    }
    for(int i=1;i<=n;i++){
      _count[i].one=_count[i-1].one+(b[i]==1);
      _count[i].zero=_count[i-1].zero+(b[i]==0);
    }
    for(int i=1;i<=n;i++){
      ans1+=(_count[n].zero-_count[i].zero)*(b[i]==1);
      ans2=max(ans2, (b[i]==1)?(_count[i].one-1-(_count[n].zero-_count[i].zero)):((_count[n].zero-_count[i].zero)-_count[i].one));
    }
    cout<<ans1+ans2<<endl;
  }
  return 0;
}
