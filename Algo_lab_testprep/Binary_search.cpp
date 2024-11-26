#include<bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int>&v,int n)
{
   for(int i=0;i<n-1;i++)
   {
	for(int j=i+1;j<n;j++)
	{
		if(v[i]>=v[j])
		{
			int temp=v[i];
			v[i]=v[j];
			v[j]=temp;
		}
	}
   }
   return;
}
int binary_search(vector<int>&v,int l,int r,int k)
{
   int mid=l+(r-l)/2;
   if(l>r) return -1;
   if(v[mid]==k)
   {
   	return mid;
   }
   else if(k<v[mid])
   {
    binary_search(v,l,mid-1,k);
   }
   else
   {
	binary_search(v,mid+1,r,k);
   }
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
	bubble_sort(v,n);
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	int k;
	cin>>k;
	int l=0;
	int r=n-1;
	int ans = binary_search(v,l,r,k);
	if(ans==-1)
	{
		cout<<"NOT_FOUND"<<endl;
	}
	else
	{
		cout<<"FOUND"<<endl;
		cout<<ans<<endl;
	}
}
