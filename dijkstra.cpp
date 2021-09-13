#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int, ll>> v[1000001];
int dist[1000001];

void dijkstra(){
    multiset<pair<ll, int>> p;
    // from  0 to all other nodes 0 based indexing
    vector<int> vis(1000001, 0);
    dist[0] = 0;
    p.insert({0, 0});
    while(p.size()){
        pair<ll, int> num = *p.begin();
	p.erase(p.begin());
	if(vis[num.second]){
	    continue;	
	}
	vis[num.second] = 1;
        for(auto z : v[num.second]){
            if(dist[num.second] + z.second < dist[z.first]){
                dist[z.first] = dist[num.second] + z.second;
                p.insert({dist[z.first], z.first});
            }
        }
    }
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
	    int x,y;
	    ll w;
	    cin>>x>>y>>w;
	    v[x].push_back({y, w});
	    //v[y].push_back({x, w});
	}
	for(int i=0;i<1000001;i++){
	    dist[i] = 1000001;
	}
	
	dijkstra();
	for(int i=2;i<=n;i++){
	    cout<<dist[i]<<" ";
	}
	return 0;
}
