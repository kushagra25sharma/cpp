#include <bits/stdc++.h>
using namespace std;
#define ll long long
// D. Playoff Tournament
// Educational Codeforces Round 110 (Rated for Div. 2)

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	t=1;
	//cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int sz = s.size();
	    char a[sz+1];
	    int dp[sz+1];
	    for(int i=0;i<sz+1;i++){
	        dp[i] = 0;
	    }
	    int i = n;
	    int ind = 0;
	    map<int, int> m;
	    while(i > 0){
	        int l = pow(2, i-1);
	        int r = pow(2, i);
	        for(int j=l;j<r;j++){
	            a[j] = s[ind];
	           // cout<<a[j]<<" ";
	            m[ind+1] = j;
	            ind++;
	        }
	        //cout<<" --- ";
	        i--;
	    }
	    int j = n;
	    while(j != 0){
	            int r = pow(2, j);
	            int l = pow(2, j-1);
	            j--;
	            for(int k=l;k<r;k++){
	                if(a[k] == '0'){
	                    if(j+1 == n){
	                        dp[k] = 1;
	                    }
	                    else{
	                        dp[k] = dp[2*k];
	                    }
	                }
	                else if(a[k] == '1'){
	                    if(j+1 == n){
	                        dp[k] = 1;
	                    }
	                    else{
	                        dp[k] = dp[2*k +1];
	                    }
	                }
	                else{
	                   if(j+1 == n){
	                       dp[k] = 2;
	                   }
	                   else{
	                       dp[k] = dp[2*k] + dp[2*k +1];
	                   }
	               }
	            }
	        }
	        //cout<<'\n';
	    int qu;
	    cin>>qu;
	    for(int i=0;i<qu;i++){ 
	        int ind;
	        char c;
	        cin>>ind>>c;
	        a[m[ind]] = c;
	        int index = m[ind];
	        while(index > 0){
	            if(a[index] == '1'){
	                if(index >= pow(2, n-1)){
	                    dp[index] = 1;
	                }
	                else{
	                    dp[index] = dp[2*index + 1];
	                }
	            }
	            else if(a[index] == '0'){
	                if(index >= pow(2, n-1)){
	                    dp[index] = 1;
	                }
	                else{
	                    dp[index] = dp[2*index];
	                }
	            }
	            else{
	                if(index >= pow(2, n-1)){
	                    dp[index] = 2;
	                }
	                else{
	                    dp[index] = dp[2*index + 1] + dp[2*index];
	                }
	            }
	            index /= 2;
	        }
	        cout<<dp[1]<<'\n';
	    }
	}
	return 0;
}
