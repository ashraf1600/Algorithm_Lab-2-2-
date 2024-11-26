#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>grid[n];
bool vis[n][n];
int dis[n][n];
vector<pair<int,int>>d={{0,1},{0,-1},{1,0},{-1,0}};
bool isvalid(int ci,int cj)
{
	if(ci>=n || ci<0 || cj>=n || cj<0 ) return false;
}
void bfs(int si,int sj)
{
	vis[si][sj]=true;
	dis[si][sj]=0;
	queue<pair<int,int>>q;
	q.push({si,sj});
	while(!q.empty())
	{
        pair<int,int>par=q.front();
        int pi=par.first;
        int pj=par.second;
        q.pop();
        for(int i=0;i<4;i++)
		{
			int ci=si+d[i].first;
			int cj=si+d[i].second;
			if(isvalid(ci,cj) && vis[ci][cj]==false)
			{
				vis[ci][cj]=true;
				dis[ci][cj]=dis[si][sj]+1;
				q.push({ci,cj});
			}
		}

	}
}
int main()
{
	memset(dis,-1,sizeof(dis));
	memset(vis,false,sizeof(vis));
    cin>>n;
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
		}
	}
	bfs(0,0);
}
