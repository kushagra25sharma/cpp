#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll, int>> a[100001];
vector<int> vis(100001, 0);

ll Prim(int x){
    // priority_queue in ascending order
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q; // first element being the smallest
    q.push({0, x});
    ll ans = 0;
    while(q.size()){
        // selecting the edge with minimum weight
        pair<ll, int> num = q.top();
        q.pop();
        if(vis[num.second]){ // checking for cycles
            continue;
        }
        vis[num.second] = 1;
        ans += num.first;
        for(auto z : a[num.second]){
            if(!vis[z.second]){
                q.push(z);
            }
        }
    }
    return ans;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
	    int u,v;
	    ll w;
	    cin>>u>>v>>w;
	    a[u].push_back({w, v});
	    a[v].push_back({w, u});
	}
	// start from any vertex
	cout<<Prim(1);
	return 0;
}

