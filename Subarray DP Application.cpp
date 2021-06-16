#include<bits/stdc++.h>
using namespace std;
// Maximum sum after splitting into subarrays taking difference of maximum and minimum of each one
// eg: [1, 2 , 1 , 0, 5] => [1,2] , [1],  [0,5] => (2-1) + (1-1) + (5-0) = 6
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> dp(n+1, 0);// dp[i+1] will be the max sum out of a[0..i] for selected `i`s.
    
    // a[start..end] will be a maximal increasing run(monotonic increasing) or a maximal decreasing run(monotonic decreasing).
    // we take the subarray in which elements are either monotonic increasing or decreasing
    for(int start=0, end; start < n-1; start = end){
        end = start + 1;
        if(a[start] <= a[end]){// monotonic increasing
            while(end+1 < n && a[end] <= a[end+1]) end++;
            // we get a sequence of increasing no [start .... end], end+1 will be less than end
            // we have 2 options either to include the last element[start...end-1] [end ... ] or not[start...end] [end+1 ...]
            for(int i=max(start+1, end-1); i<=end; i++){
                dp[i+1] = max(dp[start] + a[i] - a[start], dp[start+1] + a[i] - a[start+1]);
            }
        }
        else{// monotonic decreasing
            while(end+1 < n && a[end] >= a[end+1]) end++;
            for(int i=max(start+1, end-1); i<=end; i++){
                dp[i+1] = max(dp[start] + a[start] - a[i], dp[start+1] + a[start+1] - a[i]);
            }
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}
