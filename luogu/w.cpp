//思路：把每个人都看作一个杯子，只接水不倒水的杯子，
//对于每次倒水，从i号杯子向j号杯子里倒，有两种情况：
//1.i中水都倒向j中，j还没满
//2.i中水只能倒一部分到j，倒到j满为止
//值得注意的是，对于特殊的四个杯子，因为我们不知道刻度，所以向着四个杯子倒水只有情况1满足，2不满足

//一些细节：
//在搜索过程中，我们可能会在某几个状态之间来回横跳，为了避免这种状态，我们可以开一个Map数组
//Map数组用法，对于各个瓶中的水量，比如8，8，0，0，0，0，0，我们想记录这个状态可以用8800000来表示
//所以Map[8800000]=1表示这个状态出现过，反之=0表示没出现过
//对于出现过的状态我们就直接停止结束
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const ll N=1e4+5;
const ll M=1e8+5;
const ll zh[]={0,8,8,3,4,4,4,4};//个人习惯下标从1开始，存放每个杯子上限，我把4个人也当作特殊四个杯子，这四个杯子只能接水不能倒水
struct Node{
  ll s[10];
};
ll ans,tmp;//ans表示方案数，tmp表示每种方案所要的移动次数
Node rem[N];//rem数组是用来记录每一次各个杯子装水情况
bool Map[M];//标记状态的数组
inline ll make_digital(Node q){
  ll x=0;//sort我不知道你们学没学过，27行28行其实不写也可以，27行是将第1，2瓶水量从小到大排序，28行是将四个特殊瓶子中水量从小到大排序
  sort(q.s+1,q.s+3);//对于第一个第二个瓶子，它们其实是等价的，比如说第一二个瓶子是8，6和6，8其实是同一个状态，为了减少这个状态数，我们将第一二个瓶子水从小到大排序
  sort(q.s+4,q.s+8);//对于四个特殊瓶子，它们也是等价的，故同理操作
  for(ll i=1;i<=7;i++)x=x*10+q.s[i];
  return x;
}
void dfs(Node q){//深度优先搜索
  if(Map[make_digital(q)])return ;//33行和34行就是判断这个状态有没有经历过，若经历过就直接退出
  Map[make_digital(q)]=1;
  if((q.s[1]==0)&&(q.s[2]==0)&&(q.s[3]==0)){//此时三个杯子均没水了，说明已经完成了
    prllf("第%d种方法:\n",++ans);
    for(ll i=1;i<=tmp;i++)
      prllf("%d %d %d|%d %d %d %d\n",rem[i].s[1],rem[i].s[2],rem[i].s[3],rem[i].s[4],rem[i].s[5],rem[i].s[6],rem[i].s[7]);
    return ;
  }
  for(ll i=1;i<=3;i++){//枚举倒水容器
    if(q.s[i]==0)continue;//i号杯子没水可倒
    for(ll j=1;j<=7;j++){//枚举接水容器
      if(q.s[j]==zh[j])continue;//j号杯子是满的
      if(i==j)continue;//不能自己给自己倒水
      Node q1=q;//q1是之后将变成的状态
      ll a=zh[j]-q.s[j], b=q.s[i];//a是j号剩余容量，b是i号可倒容量
      if((j>3)&&(b>a))continue;//特殊情况
      if(b>a){//向j中倒水，直到j满
        q1.s[i]-=a;
        q1.s[j]=zh[j];
        rem[++tmp]=q1;//记录下每次各瓶中水
        dfs(q1);//下次搜索以q1为起点开始继续变换
        tmp--;//回溯（dfs中特有的一步）
      }
      else {//向j中倒水，直到i没
        q1.s[i]=0;
        q1.s[j]+=b;
        rem[++tmp]=q1;//记录下每次各瓶中水
        dfs(q1);//下次搜索以q1为起点开始继续变换
        tmp--;//回溯（dfs中特有的一步）
      }
    }
  }
}
ll main(){
  //freopen("w.out","w",stdout);//生成输出文件
  Node q0;
  for(ll i=1;i<=7;i++)q0.s[i]=0;
	q0.s[1] = q0.s[2] = 8;
  rem[++tmp] = q0;
  dfs(q0); 
  return 0;
}