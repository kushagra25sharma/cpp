#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://codeforces.com/contest/1525/problem/D
// Armchairs
ll dp[5001][5001];
vector<int> p, e;

ll solve(int i, int j){
    if(i >= p.size()){ // no person left, return 0
        return 0;
    }
    if(j >= e.size()){
        return 1e18;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    // we have 2 options either to make ith person take jth chair or to make him take another chair
    // we will take the minimum of those 2 choices 
    dp[i][j] = min(solve(i, j+1), abs(e[j] - p[i]) + solve(i+1, j+1)); 
    return dp[i][j];
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    int num;
	    cin>>num;
	    if(num){
	        p.push_back(i); // filled chairs
	    }
	    else{
	        e.push_back(i); // empty chairs
	    }
	}
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        dp[i][j] = -1;
	    }
	}
	if(p.size() == 0){
	    cout<<"0";
	    return 0;
	}
	else{
	    cout<<solve(0, 0);
	}
	return 0;
}

