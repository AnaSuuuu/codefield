#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int T, n, m, q, arity[200];
string A, term;
char x;

string property(char c){
    if (c>='a'&&c<='e') return "constant";
    if (c>='f'&&c<='h') return "function";
    if (c>='u'&&c<='z') return "variable";
    if (c>='P'&&c<='T') return "predicate";
    if (c=='(') return "connective";
    if (c=='A') return "forall";
    return "error";
}

bool isfree(int l, int r){
    string prop=property(A[l]);
    if (prop=="connective"){
        if (A[l+1]=='N')
            return isfree(l+2, r-1);
        int num=0;
        for (int i=l+1; i<r-1; ++i){
            if (A[i]=='(') num++;
            if (A[i]==')') num--;
            if (num!=0) continue;
            if (A[i]=='I')
                return isfree(l+1, i)||isfree(i+1, r-1);
        }
    }
    if (prop=="forall"){
        bool free=isfree(l+2, r);
        return free&&x!=A[l+1];
    }
    for (int i=l; i<r; ++i)
        if (A[i]==x) return true;
    return false;
}

string connect(string s1, string s2){
    if (s1=="error"||s2=="error") return "error";
    return "("+s1+"I"+s2+")";
}

string solve(int l, int r){
    string res="";
    string prop=property(A[l]);
    if (prop=="connective"){
        if (A[l+1]=='N'){
            res=solve(l+2, r-1);
            if (res=="error") return res;
            return "(N"+res+")";
        }
        int num=0;
        for (int i=l+1; i<r-1; ++i){
            if (A[i]=='(') num++;
            if (A[i]==')') num--;
            if (num!=0) continue;
            if (A[i]=='I')
                return connect(solve(l+1, i), solve(i+1, r-1));
        }
    }
    if (prop=="forall"){
        if (!isfree(l, r)) return A.substr(l, r-l);
        if (term.find(A[l+1])!=string::npos) return "error";
        res=solve(l+2, r);
        if (res=="error") return "error";
        return string("A")+A[l+1]+res;
    }
    for (int i=l; i<r; ++i)
        if (A[i]!=x) res+=A[i];
        else res+=term;
    return res;
}

int main(){
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    scanf("%d", &T);
    while (T--){
        cin>>A;
        n=A.length();
        cin>>m;
        char c; int pnum;
        for (int i=0; i<m; ++i){
            cin>>c>>pnum;
            arity[c]=pnum;
        }
        cin>>q; string ans="";
        for (int i=0; i<q; ++i){
            cin>>term>>x;
            ans=solve(0, n);
            if (ans=="error")
                cout<<"N"<<endl;
            else cout<<"Y"<<endl<<ans<<endl;
        }
    }
    //fclose(stdin); fclose(stdout);
    return 0;
}