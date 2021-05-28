#include <bits/stdc++.h>
using namespace std;
// Given a matrix, we can consider any point on the first row as entry point and any point on last row as
// exit point. # is a wall and . is empty space.
// Find the path with max length. You can only go down, right or left and visit each cell only once.
// DP Solution
vector<vector<int>> grid;
int M, N;
vector<vector<vector<int>>> dp;

int solve(int r, int c, int k){
    if(dp[r][c][k] != -1)
        return dp[r][c][k];
    if(grid[r-1][c-1] == 0)
        return 0;
    dp[r][c][k] = 0;
    if(k == 0){
        dp[r][c][k] = max(solve(r, c+1, 0), solve(r, c+1, 2)) + 1;
    }
    else if(k == 1){
        dp[r][c][k] = max(solve(r, c-1, 1), solve(r, c-1, 2)) + 1;
    }
    else{
        dp[r][c][k] = max(solve(r-1, c, 2), max(solve(r-1, c, 0), solve(r-1, c, 1))) + 1;
    }
    return dp[r][c][k];
}

int main() {
    grid = vector<vector<int>>{{0,1,0,1,1,0},
                               {0,1,0,1,1,0},
                               {0,1,0,0,1,0},
                               {0,1,1,0,1,0},
                               {0,1,1,0,1,0},
                               {0,1,1,0,1,0}};
    
    M = grid.size(), N = grid[0].size();
    
    dp = vector<vector<vector<int>>>(M+2, vector<vector<int>>(N+2, vector<int>(3, -1)));
    for(int i = 0 ; i < N+2; i++)
        dp[0][i][0] = dp[0][i][1] = dp[0][i][2] = 0;
    for(int j = 0 ; j < M+2; j++){
        dp[j][0][0] = dp[j][0][1] = dp[j][0][2] = 0;
        dp[j][N+1][0] = dp[j][N+1][1] = dp[j][N+1][2] = 0;
    }
    int ans = 0;
    for(int j = 1 ; j <= M ; j++){
        for(int i = 1; i <= N ; i++){
            ans = max(ans, solve(j, i, 0));
            ans = max(ans, solve(j, i, 1));
            ans = max(ans, solve(j, i, 2));
        }
    }
    cout << ans << endl;
    return 0;
}
