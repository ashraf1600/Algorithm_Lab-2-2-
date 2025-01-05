//DP appraoch
#include<bits/stdc++.h>
using namespace std;
int dp[1006][1006];
int knapsack(int n,int W,int w[],int v[])
{
	if(n==0 || W==0) return 0;
	if(dp[n][W]!=-1) return dp[n][W];
	if(w[n]<=W)
	{
		//duita option
		// (1)->n th wight k niye dekhbo value koto hoi
		int op1=knapsack(n-1,W-w[n],w,v)+ v[n];
		// (2)->n th wight k na niye dekhbo value koto hoi
		int op2=knapsack(n-1,W,w,v);
		dp[n][W]= max(op1,op2);
		return dp[n][W];

	}
	else
	{
	  // na niyei dekte hbe
      int op2=knapsack(n-1,W,w,v);
      dp[n][W]=op2;
      return dp[n][W];
	}
}
int main()
{
	int n,W;
	cin>>n>>W;
	int w[n],v[n];
	memset(dp, -1, sizeof(dp));
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int mx_value=knapsack(n-1,W,w,v);
	cout<<mx_value<<endl;
}

