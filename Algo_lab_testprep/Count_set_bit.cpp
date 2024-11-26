#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int cnt=0;
   while(n>0)
   {
    cnt+=(n&1);
    n>>=1;
   }
   cout<<cnt<<endl;
}
