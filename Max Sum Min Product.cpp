// https://leetcode.com/problems/maximum-subarray-min-product/submissions/
class Solution {
public:
    int maxSumMinProduct(vector<int>& a) {
        vector<long long>  dp(a.size()+1, 0);
        int n = a.size();
        for(int i=0;i<n;i++){
            dp[i+1] = dp[i] + a[i];
        }
        long long ans = 0;
        vector<int> b;
        for(int i=0;i<=n;i++){
            while(b.size() && (i == n || a[b.back()] > a[i])){
                int j = b.back();
                b.pop_back();
                long long num = dp[i];
                if(b.size()){
                    num -= dp[b.back() + 1];
                }
                num *= a[j];
                ans = max(ans, num);
            }
            b.push_back(i);
        }
        return ans%1000000007;
    }
};
