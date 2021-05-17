#include <bits/stdc++.h>
using namespace std;
#define ll long long
//Range updates and Range queries
int n, BIT1[100001], BIT2[100001]; // 1 based indexing

void update1(int index, int value){
    for(int i = index; i <= n; i += i&(-i)){
        BIT1[i] += value;
    }
}

void update2(int index, int value){
    for(int i = index; i <= n; i += i&(-i)){
        BIT2[i] += value;
    }
}

ll query1(int index){
    ll sum = 0;
    for(int i = index; i > 0; i -= i&(-i)){
        sum += BIT1[i];
    }
    return sum;
}

ll query2(int index){
    ll sum = 0;
    for(int i = index; i > 0; i -= i&(-i)){
        sum += BIT2[i];
    }
    return sum;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
	    BIT2[i] = BIT1[i] = 0;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
	    int type;
	    cin>>type;
	    if(type == 1){ // query in range
	        int l, r;
	        cin>>l>>r;
	        ll v1 = query1(r)*r - query2(r);
	        ll v2 = query1(l-1)*(l-1) - query2(l-1);
	        cout<<"Sum in the range ["<<l<<" "<<r<<"] is "<<(v1 - v2)<<"\n";
	    }
	    else{ // update in range
	        int l, r, val;
	        cin>>l>>r>>val;
	        update1(l, val);
	        update1(r+1, -val);
	        update2(l, val*(l-1));
	        update2(r+1, -val*r);
	    }
	}
	
	return 0;
}

