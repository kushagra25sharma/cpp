#include <iostream>
using namespace std;
// Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)
// You have the following 3 operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character
int minDistance(string s, string p) {
    int n = s.size();
    int m = p.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
                dp[i][j] += 1; // minimum of all possible operations + 1
            }
        }
    }
    return dp[n][m];
}

int main() {
	string s, p;
	cin>>s>>p;
	cout<<minDistance(s, p);
	return 0;
}
