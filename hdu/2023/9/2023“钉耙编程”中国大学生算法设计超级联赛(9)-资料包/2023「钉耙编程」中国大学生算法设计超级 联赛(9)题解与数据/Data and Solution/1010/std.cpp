#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n , m;
map<int,vector<pair<int,int>>>E;
map<int,int> cnt , limit;
typedef long long ll;
struct uni {
    int p[N];
    int cnt ;
    void init() {
        for(int i = 1;i <= n;i++) p[i] = i;
        cnt = n;
    }
    int Find(int x)
    {
        return p[x] == x ? x : p[x] = Find(p[x]) ;
    }
    bool Merge(int u,int v)
    {
        u = Find(u) , v = Find(v);
        if(u == v) return 0;
        p[u] = v; cnt--;
        return 1;
    }
    bool in(int u,int v)
    {
        return Find(u) == Find(v);
    }
}Un[N];
struct edge {
    int u , v , w;
};
bool mat[N][N];
int dis[N] , from[N] , mark[N];
bool tar[N];
queue<int> q;
vector<edge> I , rI;
bool bfs()
{
    for(int i = 1;i <= m;i++) mark[i] = 0 , from[i] = -1;
    int t = -1;
    while(q.size() && t == -1) {
        int u = q.front() ; q.pop();
        if(tar[u]) {t = u ; break ;}
        for(int i = 1;i <= m;i++) {
            if(mat[u][i] && dis[i] > dis[u] + 1) {
                dis[i] = dis[u] + 1; from[i] = u;
                if(tar[i]) {t = i ; break ;}
                q.push(i);
            }
        }
    }
    while(q.size()) q.pop();
    if(t == -1) {return 0;}
    while(t != -1) {
        mark[t] = 1 ; t = from[t];
    }
    vector<edge> new_I , new_rI;
    for(int i = 0;i < I.size();i++) {
        if(mark[i + 1]) new_rI.push_back(I[i]);
        else new_I.push_back(I[i]);
    }
    for(int i = 0;i < rI.size();i++) {
        if(mark[i + 1 + I.size()]) new_I.push_back(rI[i]);
        else new_rI.push_back(rI[i]);
    }
    swap(I , new_I) ; swap(rI , new_rI);
    return 1;
}
bool chk(ll lm)
{
    int sum = 0;
     I.clear() ; rI.clear();
    for(auto &[w , v] : E) {
        limit[w] = max(0LL , (ll)v.size() - lm / w) ;
        sum += limit[w];
    }
    Un[0].init();
    map<int,vector<int> > take;
    cnt.clear();
    for(auto &[w , v] : E) {
        int a,b;
        take[w].resize(v.size()); cnt[w] = v.size();
        for(int i = 0;i < v.size();i++) {
            a = v[i].first , b = v[i].second;
            if(!Un[0].in(a , b)) {
                Un[0].Merge(a , b);
                take[w][i] = 1;
                cnt[w]--;
            }
        }
    }
    for(auto &[w , v] : E) {
        int a , b;
        for(int i = 0;i < v.size() && cnt[w] > limit[w];i++) {
            if(take[w][i]) continue;
            a = v[i].first , b = v[i].second ;
            take[w][i] = 1 ; cnt[w]--;
        }
    }
    for(auto &[w , v] : E) {
        int a , b;
        for(int i = 0;i < v.size() ;i++) {
            a = v[i].first , b = v[i].second ;
            if(take[w][i]) {
                rI.push_back((edge){a , b , w});
            }
            else {I.push_back((edge){a , b , w}); }
        }
    }
    ///F1 : connect
    ///F2 : num limit
    int cc = 0;
    do{
     /*   printf("Round I : \n");
        for(auto S : I) {
            printf("%d %d %d\n",S.u,S.v,S.w);
        }
        printf("Round rI : \n");
        for(auto S : rI) {
            printf("%d %d %d\n",S.u,S.v,S.w);
        }*/
        cnt.clear() ;cc++;
        for(auto &S : I) cnt[S.w]++;
        for(int j = 1;j <= rI.size();j++) {
            Un[j].init() ;
            for(int i = 0;i < rI.size();i++) {
                if(i != j - 1) Un[j].Merge(rI[i].u , rI[i].v);
            }
        }
        for(int i = 1;i <= m;i++) for(int j = 1;j <= m;j++) mat[i][j] = 0;
        int tlm[505];
        for(int j = 0;j < rI.size();j++) tlm[j] = limit[rI[j].w];
        for(int i = 1;i <= I.size();i++) {
            for(int j = 1;j <= rI.size();j++) {
                ///i -> j , I\{i} + {j} in F1
                if(Un[j].cnt == 1 || (Un[j].cnt == 2 && !Un[j].in(I[i - 1].u , I[i - 1].v))) {mat[i][j + I.size()] = 1;}
                ///j -> i , I\{i} + {j} in F2
                if(I[i - 1].w == rI[j - 1].w) mat[j + I.size()][i] = 1;
                else if(cnt[rI[j - 1].w] < tlm[j - 1]) {mat[j + I.size()][i] = 1;}
            }
        }
        //for(int i = 1;i <= m;i++ , printf("\n")) for(int j = 1;j <= m;j++) printf("%d ",mat[i][j]);
        for(int i = 1;i <= m;i++) tar[i] = 0 , dis[i] = 1e9;
        for(int j = 1;j <= rI.size();j++) {
            if(Un[j].cnt == 1) {dis[j + I.size()] = 0 , q.push(j + I.size()); /*printf("IN_F1 %d\n",j);*/}
            if(cnt[rI[j - 1].w] < tlm[j - 1]) {tar[j + I.size()] = 1; /*printf("IN_F2 %d\n",j);*/}
        }
    }while(bfs());
    if(I.size() == sum) return 1;
    return 0;
}
ll set_min(ll x)
{
    ll sol = 0;
    for(auto &[w,v] : E) {
        sol = max(sol , x/w * w);
    }
    return sol;
}
ll set_max(ll x)
{
    ll sol = 1e18;
    for(auto &[w , v] : E) {
        sol = min(sol , (x/w + 1) * w - 1);
    }
    return sol;
}
void solve()
{
    cin >> n >> m;
    E.clear(); cnt.clear() ; limit.clear();
    ll r = 0;
    for(int i = 1;i <= m;i++) {
        int u , v , w;cin >> u >> v >> w;
        E[w].push_back(pair<int,int>{u , v});
        r = max(r , (ll)(1LL*w*E[w].size()));
    }
    ll l = 1;
    while(l < r) {
        ll md = (l + r >> 1);
        if(chk(md)) {r = md; r = max(l,set_min(r));}
        else {l = min(r , set_max(md) + 1);}
        //cout <<l<<' ' << r <<' ' <<r - l <<'\n';
    }
    cout << l << '\n';
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out2.txt","w",stdout);
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
}
