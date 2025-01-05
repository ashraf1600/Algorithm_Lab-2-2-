#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<n;i++)
	{
		int min_i=i;
     for(int j=i;j<n;j++)
	 {
		if(v[j]<=v[min_i])
		{
			min_i=j;
		}
	 }
	 swap(v[i],v[min_i]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
}
