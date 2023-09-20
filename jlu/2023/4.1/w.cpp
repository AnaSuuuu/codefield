#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std; 
const int mod=1e8;
int main()
{ 
  freopen("F.in","w",stdout);
  puts("100");
srand((unsigned)time(NULL)); 
for(int i = 0; i < 100;i++ ) 
        cout << rand()*rand()%mod << ' '<<rand()*rand()%mod<<endl;; 
cout << endl; 
return 0;
}