#include <bits/stdc++.h>
using namespace std;
#define ll long long
// C. Unstable String
// Educational Codeforces Round 110 (Rated for Div. 2)

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n = s.size();
	    ll dp[n+1][2];// dp[i][j] stores the number of valid substrings if the ith index ends with j (0 or 1).
	    for(int i=0;i<=n;i++){
	        dp[i][0] = dp[i][1] = 0;
	    }
	    ll ans = 0;
	    for(int i=1;i<=n;i++){
	        // if the ith index is '?' you would want the the alternating string ending at '?' to be
	        // as huge as possible therefore u pick dp[i — 1][0] or dp[i — 1][1] depending which is bigger. 
	        if(s[i-1] == '?'){
	            dp[i][0] = dp[i-1][1] + 1ll;
	            dp[i][1] = dp[i-1][0] + 1ll;
	        }
	        else if(s[i-1] == '0'){ 
	       // If character at ith index is '0' you can't do anything but take transition from 
	       // previous index's '1' that is dp[i-1][1]
	            dp[i][0] = dp[i-1][1] + 1ll;
	        }
	        else{ // similarly when char at index i is '1'
	            dp[i][1] = dp[i-1][0] + 1ll;
	        }
	        ans += max(dp[i][0], dp[i][1]);
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
