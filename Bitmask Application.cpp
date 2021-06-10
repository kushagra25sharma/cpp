class Solution {
public:
    // https://leetcode.com/contest/biweekly-contest-48/problems/maximize-score-after-n-operations/
    int dp[14][20000];
    
    int solve(vector<int>& a, int cnt, int mask){
        int n = a.size();
        if(cnt > n/2){
            return 0;
        }
        if(dp[cnt][mask] != -1){
            return dp[cnt][mask];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int nmask = ((1<<i)|(1<<j));
                if((mask&nmask) == 0){ // picking the two elements that haven't been picked already
                    ans = max(ans, cnt*(__gcd(a[i], a[j])) + solve(a, cnt+1, (mask|nmask)));
                }
            }
        }
        return dp[cnt][mask] = ans;
    }
    
    int maxScore(vector<int>& nums) {
        for(int i=0;i<14;i++){
            for(int j=0;j<20000;j++){
                dp[i][j] = -1;
            }
        }
        return solve(nums, 1, 0);
    }
};
