// https://leetcode.com/problems/minimum-cost-to-merge-stones/
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
         // After a merge we are left with N-(K-1) elements & after another merge N- 2*(K-1) & in the end only 1 element will remain
        //So m(K-1) + 1 = N   => m(K-1) = N - 1   Therefor m(no of swaps) should be an integer
        if((n-1)%(k-1)){
            return -1;
        }
        int dp[n][n];
        int prefix[n+1];
        prefix[0] = 0;
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + stones[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = 0;
            }
        }
        for(int len=k;len<=n;len++){ // len = length of current substring
            for(int i=0;i<=n-len;i++){
                int j = i + len - 1;
                dp[i][j] = 1e7;
                // mid divides i-j into (1, rest), (K, rest), (2K-1, rest), etc....
                // The reason to calculate sub-problems which are not real merges, is to copy over the minimum of previous merge costs towards caculating the next real merge
                for(int mid=i; mid<j;mid += k-1){
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid+1][j]);
                }
                if((j-i)%(k-1) == 0){ // add only when overlapping is possible
                    dp[i][j] += prefix[j+1] - prefix[i];
                }
            }
        }
        return dp[0][n-1];
    }
};
