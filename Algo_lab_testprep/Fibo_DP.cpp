#include<bits/stdc++.h>
using namespace std;
vector<int>dp(1006,-1);
int Fib(int n)
{
	if(n==0 || n==1) return n;
	if(dp[n]!=-1) return dp[n];
	dp[n]= Fib(n-1) + Fib(n-2);
	return dp[n];
}
int main()
{
	int n;
	cin>>n;
	int ans=Fib(n);
	cout<<ans<<endl;
}
