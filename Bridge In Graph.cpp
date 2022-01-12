#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int> v[200001];
int currTime = 0;

void dfs(int low[], int disc[], int vis[], int parent, int vertex){
    currTime += 1;
    vis[vertex] = 1;
    disc[vertex] = low[vertex] = currTime;
    for(auto z : v[vertex]){
        if(z == parent) continue; // if z == parent than it means we are going backwards or it's a cycle we need to move forward
        if(!vis[z]){
            dfs(low, disc, vis, vertex, z);
            low[vertex] = min(low[vertex], low[z]); // if there is a way to visit vertex earlier than current time.
            if(low[z] > disc[vertex]){ // it means there is no other way to visit z. vertex has to be visited before we move to z
                cout<<vertex<<" "<<z<<" -- ";
            }
        }
        else{
            // if z is previously visited then the lowest time will be the discovery time.
            low[vertex] = min(low[vertex], disc[z]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int low[n] = {200001};
    int disc[n]= {0};
    int vis[n] = {0};
    dfs(low, disc, vis, -1, 0);
    return 0;
}
