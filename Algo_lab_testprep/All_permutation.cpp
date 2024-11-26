#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void all_per(vector<int>&v,int ind)
{
	if(ind>=v.size())
	{
		ans.push_back(v);
		return;
	}
	for(int i=ind;i<v.size();i++)
	{
		swap(v[i],v[ind]);
		all_per(v,ind+1);
		swap(v[i],v[ind]);
	}
}
int main()
{
	int n;	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	all_per(v,0);
	for(auto x:ans)
	{
		for(auto u:x)
		{
			cout<<u<<" ";
		}
		cout<<endl;
	}
}
