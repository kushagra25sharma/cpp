#include <iostream>
#include <vector>
using namespace std;

void markConnected(int node, vector<vector<int>>& v, vector<int>& vis){
    vis[node] = 1;
    for(int& x : v[node]){
        if(!vis[x]) markConnected(x, v, vis);
    }
}

int printMaxEdgesRemoved(int n, int m, vector<vector<int>>& edges, int& k){
    vector<vector<int>> v(n);
    for(int i=0;i<m;i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(n, 0);
    int connectedComp = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            connectedComp++;
            markConnected(i, v, vis);
        }
    }
    if(connectedComp > k) return -1;
    // max edges that can be removed:
    // for a connected component of c nodes there will be at min c-1 edges
    // so for our total connected components let c1, c2...cn be the no: of nodes
    // c1-1 + c2-1 + ... + cn-1 = n(total nodes) - c(connectedComp)
    // as {c1 + c2 + .. + cn = n) 
    // we need to remove n-c edges from total m edges so ans = m - (n-c)
    // further we need to have k connected components so we need to remove (k-c) edges as c connected
    // comps we already have, we just need to make (k-c) more
    // so final ans = m - (n-c) + (k-c) = m - n + k
    return m - n + k;
}

int main() {
	int n, m, k; // no: of nodes, no: of edges, no: of connected components required
	cin>>n>>m>>k;
	vector<vector<int>> edges(m, vector<int> (2));
	for(int i=0;i<m;i++){
	    cin>>edges[i][0]>>edges[i][1];
	    edges[i][0] -= 1;
	    edges[i][1] -= 1;
	}
	cout<<printMaxEdgesRemoved(n, m, edges, k);
	return 0;
}
