#include <bits/stdc++.h>
using namespace std;
vector<int> rearrangeArray(vector<int>&nums)
{
        vector<int>ans;
        vector<int>pos,neg;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                neg.push_back(nums[i]);
            }
            else pos.push_back(nums[i]);
        }
        int k=0;
        int l=0;
    for(int i=0;i<nums.size();i++)
    {

        if(i%2==0)
        {
            ans.push_back(pos[k]);
            k++;
        }
        else
        {
            ans.push_back(neg[l]);
            l++;
        }
    }
   return ans;
}

int main()
{
    int n;
    cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++)
	{
		cin>>nums[i];
	}
	vector<int>v=rearrangeArray(nums);
	for(int i=0;i<n;i++)
	{

		cout<<v[i]<<" ";
	}
}

