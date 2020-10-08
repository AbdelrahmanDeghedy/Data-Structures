#include <bits/stdc++.h>

using namespace std;
int BFS (vector <vector <int>> & adj, int s)
{
    int ans = 1;
    vector <int> dis (100009, INT_MAX);
    queue <int> q;
    q.push (s);
    dis[s] = 1;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < (int) adj[parent].size(); i++)
        {
            int child = adj[parent][i];
            if (dis[child] == INT_MAX)
            {
                q.push (child);
                dis[child] = dis[parent] + 1;
                ans = dis[child];
            }
        }
    }
    return ans;

}


int main()
{
    vector <vector <int>> adj (100009);
    int n, x, root;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == -1)
            root = i;
        else
            adj[x].push_back (i);
    }
    cout << BFS (adj, root);

    return 0;
}
