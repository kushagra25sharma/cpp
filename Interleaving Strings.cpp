//Leetcode: Interleaving Strings
// Given string s1, s2 and s3. Check if s3 is formed by an interleaving of s1 and s2
// eg s1 = aabcc s2 = dbbca
//    s3 = aadbbcbcac
//         1122221121 // 1: element of string s1 2: element of string s2
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n+m != s3.size()){
            return 0;
        }
        //dp[i][j]:  whether the first i+j elements of s3 is the interleaving string of first i elements of s1 and first j elements of s2
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0 && j == 0){// both strings are empty
                    dp[i][j] = 1;
                    continue;
                }
                if(i == 0){ // if jth char of s2 == jth char of s3 & all prev chars are good
                    dp[i][j] = dp[i][j-1] and s2[j-1] == s3[i+j-1];
                    continue;
                }
                if(j == 0){ // if jth char of s2 == jth char of s3 & all prev chars are good
                    dp[i][j] = dp[i-1][j] and s1[i-1] == s3[i+j-1];
                    continue;
                }
                // check for both of them
                dp[i][j] = dp[i-1][j] and s1[i-1] == s3[i+j-1] || dp[i][j-1] and s2[j-1] == s3[i+j-1];
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return dp[n][m];
    }
}; 
