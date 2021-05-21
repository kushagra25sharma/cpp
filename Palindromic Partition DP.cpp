#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Palindromic Partition DP
// minimum no of cuts required to partition a string such that all its substrings are palindrome

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	int n = s.size();
	int dp[n][n]; // dp[i][j] => s[i..j] is a palindrome
	int c[n]; // c[i] => minimum no of cuts required to partition substring[0...i] such that all its substrings are palindrome
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        dp[i][j] = 0;
	        if(i == j){ // every single character is a palindrome in itself
	            dp[i][j] = 1;
	        }
	    }
	}
	for(int l = 2; l <= n; l++){
	    for(int i = 0; i <= n - l; i++){
	        int j = i + l - 1;
	        if(l == 2){ // if length is 2 we check the adjacent characters
	            dp[i][j] = (s[i] == s[j]);
	        }
	        else{ // we check for the substring s[i+1....j-1] if it is a palindrome and s[i] == s[j] that
	            // means  substring s[i...j] is a palindrome
	            dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
	        }
	    }
	}
	
	for(int i = 0; i < n; i++){
	    if(dp[0][i]){ // if s[0...i] is a palindrome no cuts are required
	        c[i] = 0;
	    }
	    else{
	        c[i] = INT_MAX;
	        for(int j = 0; j < i; j++){// count the minimum no of cuts required to make all substrings of s[0...i] palindrome
	            if(dp[j+1][i] && c[j] + 1 < c[i]){
	                c[i] = c[j] + 1;
	            }
	        }
	    }
	}
	
	cout<<c[n-1];
	return 0;
}
