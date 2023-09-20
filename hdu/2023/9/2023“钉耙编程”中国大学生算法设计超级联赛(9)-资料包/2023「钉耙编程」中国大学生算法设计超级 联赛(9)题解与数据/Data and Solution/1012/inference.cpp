#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxm=105, maxk=205;
int T, n, m, k;
int fir[maxm], nxt[maxk], to[maxk], cnte, a[maxm], cnt[maxm][81], cnt2[maxm][243];
int vis[maxm];

void addedge(int x, int y){
    nxt[++cnte]=fir[x]; fir[x]=cnte;
    to[cnte]=y;
}

void dfs(int x){
    if (vis[x]) return;
    vis[x]=true;
    for (int t=fir[x]; t; t=nxt[t])
        dfs(to[t]);
}

int main(){
    //freopen("data.in", "r", stdin);  //
    //freopen("data.out", "w", stdout);  //
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &n, &m, &k);
        int x, y; cnte=0;
        memset(fir, 0, sizeof(fir));
        for (int i=1; i<=k; ++i){
            scanf("%d%d", &x, &y);
            addedge(y, x);  //反向建特征的关系图
        }
        memset(cnt, 0, sizeof(cnt));
        memset(cnt2, 0, sizeof(cnt2));
        memset(vis, 0, sizeof(vis));
        dfs(m);
        for (int i=0; i<n; ++i){  //计算模式出现次数
            for (int j=1; j<=m; ++j)
                scanf("%d", &a[j]);  //读取这组特征
            for (int j=1; j<=m; ++j){
                int id=0;
                for (int t=fir[j]; t; t=nxt[t])
                    id=id*3+a[to[t]];  //算相关特征取值id
                cnt[j][id]++;
                id=id*3+a[j];  //包含自身特征取值的id
                cnt2[j][id]++;
            }
        }
        for (int j=1; j<m; ++j)
            scanf("%d", &a[j]);
        double p, ans=-1e9; int best=0;
        for (int i=0; i<3; ++i){
            p=0;
            a[m]=i;
            int id=0;
            for (int j=1; j<=m; ++j){  //读取模式的概率
                if (!vis[j]) continue;  //与最终特征无关
                id=0;
                for (int t=fir[j]; t; t=nxt[t])
                    id=id*3+a[to[t]];  //算相关特征取值id
                //printf("%d\n", cnt[j][id]);
                p-=log(cnt[j][id]);
                id=id*3+a[j];
                p+=log(cnt2[j][id]);
                //printf("%d %d %d %d\n", i, j, id, cnt2[j][id]);
            }
            //printf("%d %lf\n", i, p);
            if (p>ans) ans=p, best=i;
        }
        printf("%d\n", best);
    }
    //fclose(stdin); fclose(stdout);  //
    return 0;
}