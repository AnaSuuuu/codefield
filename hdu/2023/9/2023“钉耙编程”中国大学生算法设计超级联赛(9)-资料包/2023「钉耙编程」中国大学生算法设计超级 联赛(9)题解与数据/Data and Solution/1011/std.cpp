#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	register int res=0;
	register char c=getchar(),f=1;
	while(c<48||c>57){if(c=='-')f=0;c=getchar();}
	while(c>=48&&c<=57)res=(res<<3)+(res<<1)+(c&15),c=getchar();
	return f?res:-res;
}
inline void write(int x){
	register char c[21];
	int len=0;
	if(!x)return putchar('0'),void();
	if(x<0)x=-x,putchar('-');
	while(x)c[++len]=x%10,x/=10;
	while(len)putchar(c[len--]+48);
}
#define space(x) write(x),putchar(' ')
#define enter(x) write(x),putchar('\n')

const int mod=998244353;
inline int inc(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int dec(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return (ll)x*y%mod;}
inline int qpow(int x,int y){
	int res=1;
	for(;y;y>>=1)res=y&1?mul(res,x):res,x=mul(x,x);
	return res;
}
inline int inv(int x){return qpow(x,mod-2);}

const int N=1<<19;
namespace NTT{
int re[N],w[2][N];
inline int getre(int n){
	int len=1,bit=0;
	while(len<n)len<<=1,++bit;
	for(int i=1;i<len;++i)re[i]=(re[i>>1]>>1)|((i&1)<<(bit-1));
	w[0][0]=w[1][0]=1,w[0][1]=qpow(3,(mod-1)/len),w[1][1]=inv(w[0][1]);
	for(int o=0;o<2;++o)for(int i=2;i<len;++i)
		w[o][i]=mul(w[o][i-1],w[o][1]);
	return len;
}
inline void NTT(int* a,int n,int o=0){
	for(int i=1;i<n;++i)if(i<re[i])swap(a[i],a[re[i]]);
	int R;
	for(int k=1;k<n;k<<=1)
		for(int i=0,t=k<<1,st=n/t;i<n;i+=t)
			for(int j=0,nw=0;j<k;++j,nw+=st)
				R=mul(a[i+j+k],w[o][nw]),a[i+j+k]=dec(a[i+j],R),a[i+j]=inc(a[i+j],R);
	if(o){
		R=inv(n);
		for(int i=0;i<n;++i)a[i]=mul(a[i],R);
	}
}

int t0[N],t1[N],t2[N];
inline void multi(const int* a,const int* b,int* c,int n,int m){
	if(n+m<=32){
		memset(c,0,sizeof(int)*(n+m+1));
		for(int i=0;i<=n;++i)
			for(int j=0;j<=m;++j)
				c[i+j]=inc(c[i+j],mul(a[i],b[j]));
		return;
	}
	int len=getre(n+m+1);
	memset(t0,0,sizeof(int)*len),memcpy(t0,a,sizeof(int)*(n+1));
	memset(t1,0,sizeof(int)*len),memcpy(t1,b,sizeof(int)*(m+1));
	NTT(t0,len),NTT(t1,len);
	for(int i=0;i<len;++i)t0[i]=mul(t0[i],t1[i]);
	NTT(t0,len,1);
	memcpy(c,t0,sizeof(int)*(n+m+1));
}
inline void inver(const int* a,int* b,int n){
	int len=1;
	while(len<=n)len<<=1;
	memset(t0,0,sizeof(int)*len),memcpy(t0,a,sizeof(int)*(n+1));
	memset(t1,0,sizeof(int)*(len<<1));
	memset(t2,0,sizeof(int)*(len<<1));
	t2[0]=inv(t0[0]);
	for(int k=1;k<=len;k<<=1){
		memcpy(t1,t0,sizeof(int)*k);
		getre(k<<1);
		NTT(t1,k<<1),NTT(t2,k<<1);
		for(int i=0;i<(k<<1);++i)t2[i]=mul(t2[i],dec(2,mul(t1[i],t2[i])));
		NTT(t2,k<<1,1);
		for(int i=k;i<(k<<1);++i)t2[i]=0;
	}
	memcpy(b,t2,sizeof(int)*(n+1));
}
} //namespace NTT

struct poly:public vector<int>{
	inline int time()const{return size()-1;}
	inline poly(int tim=0,int c=0){
		resize(tim+1);
		if(tim>=0)at(0)=c;
	}
	inline poly operator%(const int& n)const{
		poly r(*this);
		r.resize(n);
		return r;
	}
	inline poly operator%=(const int& n){
		resize(n);
		return *this;
	}
	inline poly operator+(const poly& p)const{
		int n=time(),m=p.time();
		poly r(*this);
		if(n<m)r.resize(m+1);
		for(int i=0;i<=m;++i)r[i]=inc(r[i],p[i]);
		return r;
	}
	inline poly operator-(const poly& p)const{
		int n=time(),m=p.time();
		poly r(*this);
		if(n<m)r.resize(m+1);
		for(int i=0;i<=m;++i)r[i]=dec(r[i],p[i]);
		return r;
	}
	inline poly operator*(const poly& p)const{
		poly r(time()+p.time());
		NTT::multi(&((*this)[0]),&p[0],&r[0],time(),p.time());
		return r;
	}
	inline poly operator*(const int& k)const{
		poly r(*this);
		int n=time();
		for(int i=0;i<=n;++i)r[i]=mul(r[i],k);
		return r;
	}
	inline poly operator~()const{
		poly r(*this);
		reverse(r.begin(),r.end());
		return r;
	}
};

inline poly inv(const poly& a){
	poly r(a.time());
	NTT::inver(&a[0],&r[0],a.time());
	return r;
}
inline poly der(const poly& a){
	int n=a.time();
	poly r(n-1);
	for(int i=1;i<=n;++i)r[i-1]=mul(a[i],i);
	return r;
}
int _[N];
inline poly itr(const poly& a){
	int n=a.time();
	poly r(n+1);
	_[1]=1;
	for(int i=2;i<=n+1;++i)_[i]=1LL * _[mod%i]*(mod-mod/i) % mod;
	for(int i=0;i<=n;++i)r[i+1]=1LL * a[i]*_[i+1] % mod;
	return r;
}
inline poly ln(const poly& a){
	return itr(der(a)*inv(a)%a.time());
}
inline poly exp(const poly& a){
	poly r(0,1);
	int n=a.time(),k=1;
	while(r.time()<n)
		r%=k,r=r*(a%k-ln(r)+poly(0,1))%k,k<<=1;
	return r%(n+1);
}
inline poly qpow(const poly& a,int k){
	return exp(ln(a)*k);
}

inline poly operator/(const poly& f,const poly& g){
	int n=f.time()-g.time()+1;
	return ~((~f)*inv((~g)%n)%n);
}
inline poly operator%(const poly& f,const poly& g){
	if(f.time()<g.time())return f;
	return (f-g*(f/g)%g.time())%g.time();
}

inline void read(poly& a,int n=-1){
	if(!~n)n=a.time();
	else a.resize(n+1);
	for(int i=0;i<=n;++i)a[i]=read();
}
inline void write(const poly& a,int n=-1){
	if(!~n)n=a.time();
	else n=min(n,a.time());
	for(int i=0;i<n;++i)space(a[i]);
	enter(a[n]);
}


int n , m , k;
int a[200005],cnt[200005];
int kd[200005] , r[200005];
void solve()
{
    n = read() , m = read() , k = read();
    for(int i = 1;i <= m;i++) a[i] = 0;
    for(int i = 1;i <= n;i++)cnt[i] = 0;
    for(int i = 1;i <= n;i++) {
        a[read()]++;
    }
    poly w(n);
    for(int i = 1;i <= m;i++) {
        cnt[a[i]]++;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = i ; j <= n ;j += i) w[j] = (w[j] - 1LL*cnt[i]*r[j / i]%mod + mod) % mod;
    }
    w = exp(w) ; ///w[i] = (x/e^x)^i * e^n = x^i * e^(n - i)
    /// [x^k] e^(n - i) * x^i <=>
    /// [x^(k - i)] e^(n - i)
    /// (n-i)^(k-i) / (k-i)!
    ///contri = (n-i)^(k-i) * k^(i,down)
    kd[0] = 1;
    for(int i = 1;i <= n && i <= k;i++) kd[i] = 1LL*kd[i - 1]*(k - i + 1) % mod;
    int ans = 0;
    for(int i = 0;i <= n && i <= k;i++) {
        ans = (ans + 1LL*w[i]*qpow(n - i , k - i) % mod * kd[i]) % mod;
    }
   // cout << ans << '\n';
    ans = 1LL*ans*qpow(qpow(n , mod - 2) , k) % mod;
    cout << ans << '\n';
    return;

}
int main()
{
   // freopen("in.txt","r",stdin);
    for(int i = 1;i <= 200000;i++) r[i] = qpow(i , mod - 2);
    int t ; t = read();
    while(t--) solve();
    return 0;
}
