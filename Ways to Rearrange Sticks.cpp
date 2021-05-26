//Leetcode: There are n uniquely-sized sticks whose lengths are integers from 1 to n. You want to arrange the sticks such
//that exactly k sticks are visible from the left. A stick is visible from the left if there are no longer sticks to the left of it.
class Solution {
public:
    long long dp[1001][1001];
    long long mod = 1e9 + 7;
    
    long long solve(int n, int k){
        if(k == 0 || k > n){
            return 0;
        }
        if(n <= 2){
            return 1;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        long long ans = 0;
        // select the tallest stick. So now we can choose from n-1 sticks and have k-1 positions to the left of the tallest stick
        ans = (ans%mod + solve(n-1, k-1)%mod)%mod;
        
        // select the stick that is not the tallest one and check that if it is visible from the left
        // eg 2 positions and 4 sticks. Possible combinations can be
        // 1 4, 2 4, 3 4, 1 3, 2 3, 1 2
        ans = (ans%mod + ((n-1)*(solve(n-1, k)))%mod)%mod;
        
        return dp[n][k] = ans;
    }
    
    int rearrangeSticks(int n, int k) {
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j] = -1;
            }
        }
        return solve(n, k);
    }
};
