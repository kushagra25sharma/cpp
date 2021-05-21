#include <bits/stdc++.h>
using namespace std;
#define ll long long
//Kosaraju's Algorithm for finding strongly connected components
vector<int> a[10001], rev[10001], vis(10001, 0);
stack<int> s;

void dfs1(int num){ // doing dfs to visit all the nodes and fill the stack.  
    vis[num] = 1;
    for(auto z : a[num]){
        if(!vis[z]){
            dfs1(z);
        }
    }
    // All the vertices which can be visited from num is already being processed
    s.push(num);
}

void dfs2(int num){// doing dfs on reversed graph and printing the strongly connected elements
    vis[num] = 1;
    cout<<num<<" ";
    for(auto z : rev[num]){
        if(!vis[z]){
            dfs2(z);
        }
    }
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
	    int u, v;
	    cin>>u>>v;
	    u--,v--;
	    a[u].push_back(v);
	    rev[v].push_back(u);
	}
	for(int i=0;i<n;i++){
	    if(!vis[i]){// if we have disconnected graph we have to do dfs on all the components
	        dfs1(i);
	    }
	}
	for(int i=0;i<n;i++){
	    vis[i] = 0;
	}
	cout<<"The strongly connected components are: \n";
	int sumc = 0, sumd = 0;
	while(s.size()){
	    int num = s.top();
	    s.pop();
	    if(!vis[num]){ // if vertex is not visited that means there is another component in the graph
	        dfs2(num);
	        cout<<"\n";
	    }
	}
	return 0;
}
