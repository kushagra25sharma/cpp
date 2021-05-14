// Finding the LCA (Least Common Ancestor) of two nodes 
// root node will always be 0 in this problem
// Binary Lifting
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int LOG = 20;
vector<int> a[100001];
vector<vector<int>> up(100001, vector<int> (20));
vector<int> depth(100001);

void dfs(int num){ // doing dfs to fill all the ancestors which are at 2^j (0<=j<LOG) from the current vertex
    for(auto x : a[num]){
        up[x][0] = num; // parent of curr vertex (ancestor at length 1)
        depth[x] = depth[num] + 1; // depth of current vertex will be 1 more than its parent
        
        for(int j=1;j<LOG;j++){// filling the other indices 
            up[x][j] = up[ up[x][j-1] ][j-1];
        }
        dfs(x);
    }
}

int query(int u, int v){
    if(depth[u] < depth[v]){ // if depth of v is greater than u swap them
        swap(u, v);
    }
    int k = depth[u] - depth[v]; // diiference of the depth
    // we will first bring the nodes at same level and then we calculate the LCA
    for(int i = LOG-1; i>=0; i--){
        if(k & (1 << i)){ // taking node u to the level of v
            u = up[u][i];
        }
    }
    if(u == v){ 
        return u;
    }
    
    for(int i=(LOG-1);i>=0;i--){ 
        if(up[u][i] != up[v][i]){ // if the ancestors of the nodes i level up is not the same update their values with their ancestors
            u = up[u][i];
            v = up[v][i];
        }
    }
    // Now the parent of u & v will be the LCA 
    return up[u][0];
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	t=1;
	//cin>>t;
	while(t--){
	    int n;
	    cin>>n; // no of nodes
	    for(int i=0;i<n;i++){
	        int m;
	        cin>>m; // m children of node i
	        for(int j=0;j<m;j++){
	            int num;
	            cin>>num;
	            a[i].push_back(num);
	        }
	    }
	    dfs(0); // in this problem the tree is always rooted at 0
	    int q;
	    cin>>q; // no of queries
	    for(int i=0;i<q;i++){
	        int u, v;
	        cin>>u>>v; // find LCA of u & v
	        cout<<query(u, v)<<'\n';
	    }
	}
	return 0;
}
