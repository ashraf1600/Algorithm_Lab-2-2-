#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp(1006,vector<int>(1006,-1));
int NcR(int n,int r)
{
	if(r==n || r==0 ) return 1;
	if(dp[n][r]!=-1) return dp[n][r];
	dp[n][r]=NcR(n-1,r-1)+NcR(n-1,r);
	return dp[n][r];

}
int main()
{
	int n,r;
	cin>>n>>r;
	int ans=NcR(n,r);
	cout<<ans<<endl;
}
