#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Matrix Chain Multiplication dp
// Efficient way to multiply the matrices such that total operations are minimum. Print min no of operations
// Eg: A = 10x30, B = 30x5, C = 5x60 
// (AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations 
// A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	int dp[n][n];
	for(int i=1;i<n;i++){
	    dp[i][i] = 0;
	}
	// 0th column and 0th row aren't used and the when i == j the cost is 0 because it is a single matrix, it is not multiplied with any matrix
	for(int l=2;l<n;l++){// no of matrices to be multiplied
	    for(int i=1;i<=n-l;i++){ //0..l l+1..2l 2l+1....n 
	        int j = i+l-1;
	        dp[i][j] = INT_MAX;
	        for(int k=i;k<j;k++){ // eg 1 to 3  combinations: (AB)C A(BC) checking for all of them
	        // matrix multiplication: (n x p)(p x m) = (n x m) total operations = (n x p x m)
	            int sum = dp[i][k] + dp[k+1][j] + a[i-1]*a[k]*a[j];
	            if(sum < dp[i][j]){
	                dp[i][j] = sum;
	            }
	        }
	    }
	}
	cout<<dp[1][n-1];
	return 0;
}


