#include<stdio.h>
#include<string.h>
const int N=1e5+5;
char s[N],zh[]={'r','e','x'};
int pos[5],len;//lenΪ�ַ�������,pos����Ϊ��һ�ּ�¼������r,e,x��λ�� 
bool map[N];//
bool check(){//�жϻ��ܲ�����ɾ 
  int j=0;
  for(int i=0;i<len;i++){
    if(map[i])continue;
    if((s[i]==zh[j])||(s[i]+'a'-'A'==zh[j])||(s[i]==zh[j]+'a'-'A')){
      j++;
      if(j==3)return true;
    }
  }
  return false;
}
int main(){
  freopen("w.in","r",stdin);
  freopen("w.out","w",stdout);
  scanf("%s",s);
  len=strlen(s);
  while(check()){
    int j=0;
    for(int i=0;i<len;i++){
      if(map[i])continue;
      if((s[i]==zh[j])||(s[i]+'a'-'A'==zh[j])||(s[i]==zh[j]+'a'-'A')){
        pos[j]=i;
        j++;
        if(j==3){//����һ�ֵ�rex��������� 
          map[pos[0]]=1;
          map[pos[1]]=1;
          map[pos[2]]=1;
        }
        j%=3;
      }
    }
  }
  for(int i=0;i<len;i++){
    if(map[i])continue;
    else printf("%c",s[i]);
  }
}
