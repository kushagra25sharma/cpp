// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
class Solution {
public:
    int dp[103][103];
    
    int solve(vector<int>& cuts, int i, int j){
        if(j-i <= 1){
            return 0;
        }
        if(dp[i][j]){
            return dp[i][j];
        }
        dp[i][j] = 1e7;
        for(int k=i+1;k<j;k++){
            dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + solve(cuts, i, k) + solve(cuts, k, j));
        }
        return dp[i][j];
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        for(int i=0;i<=cuts.size();i++){
            for(int j=0;j<=cuts.size();j++){
                dp[i][j] = 0;
            }
        }
        sort(cuts.begin(), cuts.end());
        return solve(cuts, 0, cuts.size() - 1);
    }
};
