int dfs(int u,int l,vector<vector<int>>&adj,vector<bool>&vis)
{
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++)
    {
        if(!vis[adj[u][i]])
        {
            if(dfs(adj[u][i],u,adj,vis))
            return 1;
        }
        else if(vis[adj[u][i]] && adj[u][i]!=l)
        return 1;
    }
    return 0;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>>adj(A+1);
    vector<bool>vis(A+1,false);
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    for(int i=1;i<=A;i++)
    {
        if(!vis[i]&&dfs(i,-1,adj,vis))
        return 1;
    }
    
    return 0;
}
