#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Codeforces Round #724 (Div. 2)
// D. Omkar and Medians

//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
//namespace
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<ll> a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int f = 0;
	    ordered_set s;
	    int left=0, right=0, bl=0, br=0;
	    // bl -> no of elements remaining in the left from previous steps
	    // br -> no of elements remaining in the right from previous steps
	    // left-> no of elements to the left of a[i] which are present in set
	    // right-> no of elements to the right of a[i] which are present in set
	    for(int i=0;i<n;i++){
	        s.insert(a[i]);
	        
	        int sum = 2*(i+1) - 1; // total lenght of array
	        left = s.order_of_key(a[i]); // no of elements less than a[i]
	        right = s.size() - left - 1; // no of elements greater than a[i];
	        int rem = sum - s.size() - bl - br; // no of elements remaining that are to be filled
	        
	        //cout<<left<<" "<<bl<<" "<<right<<" "<<br<<" "<<rem<<" -- ";
	        
	        // the no of elements to the left of median = no of elements to the right
	        // if this is not the case we have to add elements
	        
	        int lf = 0;// no of elements we have to add
	        if(left + bl < right + br){ // if available left + previous left < available right + previous right
	            lf = right + br - left - bl;
	            bl += lf;
	        }
	        else if(left + bl > right + br){
	            lf = left + bl - right - br;
	            br += lf;
	        }
	        rem -= lf; // subtracting the remaining spaces with the no of elements we have to add
	        //cout<<bl<<" "<<br<<" "<<rem<<"\n";
	        if(rem < 0){ // if less than 0 that means array is not good
	            f=1;
	            break;
	        } 
	        if(rem == 2){
	            bl++;
	            br++;
	        }
	    }
	    if(f){
	        cout<<"NO"<<"\n";
	    }
	    else{
	        cout<<"YES"<<'\n';
	    }
	}
	return 0;
}
