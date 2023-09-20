#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e6;
int f[N];
void init(){
    fill(f+2,f+N,N);
    for(int i=1;i<N;i++){
        if(i*2<N) f[i*2]=min(f[i*2],f[i]+1);
        if(i*3<N) f[i*3]=min(f[i*3],f[i]+1);
        if(i+1<N) f[i+1]=min(f[i+1],f[i]+1);
    }
}
unordered_map<ll,int> mp;
ll solve(ll n){
    if(n<N) return f[n];
    if(mp.count(n)) return mp[n];
    return mp[n]=min(
        solve(n/2)+n%2+1,
        solve(n/3)+n%3+1
    );
};
ll solve(){
    ll n;
    cin>>n;
    return solve(n);
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int tt=clock();
    init();
    int t=1; cin>>t;
    while(t--) cout<<solve()<<'\n';
    // cout<<clock()-tt<<endl;
    return 0;
}