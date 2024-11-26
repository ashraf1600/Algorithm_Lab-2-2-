#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
vector<int> graph[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> idg(n + 1, 0);

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        idg[v]++;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << idg[i] << " ";
    }
    cout << endl;

    queue<int> q;
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        if (idg[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto it : graph[cur])
        {
            idg[it]--;
            if (idg[it] == 0)
            {
                q.push(it);
                ans.push_back(it);
            }
        }
    }

    if (ans.size() != n)
    {
        cout << "Graph has a cycle, topological sort is not possible." << endl;
    }
    else
    {
        for (auto u : ans)
        {
            cout << u << " ";
        }
    }

    return 0;
}
