#include<bits/stdc++.h>
using namespace std;
int l_bound(vector<int>&v,int val)
{
	int l=0;
	int r=v.size()-1;
	int ans=v.size();
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(v[mid]>=val)
		{
          ans=mid;
          r=mid-1;
        }
        else if(v[mid]<val)
		{

			l=mid+1;
		}
	}
  return ans;
}
int u_bound(vector<int>&v,int val)
{
	int l=0;
	int r=v.size()-1;
	int ans=v.size();
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(v[mid]>val)
		{
          ans=mid;
          r=mid-1;
        }
        else if(v[mid]<val)
		{

			l=mid+1;
		}
	}
  return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int val;
	while(true)
	{
	cin>>val;
	if(val==-1) break;
	int lb=l_bound(v,val);
	int ub=u_bound(v,val);
	cout<<lb<<endl;
	}
}
