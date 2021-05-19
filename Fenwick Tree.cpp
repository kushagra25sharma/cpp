#include <bits/stdc++.h>
using namespace std;
#define ll long long
//Point Update, Range Sum Query Binary Indexed Tree
int n, BIT[100001], a[100001]; // 1 based indexing

void update(int index, int num){
    for(int i = index; i <= n; i += i&(-i)){
        BIT[i] += num;
    }
}

int query(int index){
    ll sum = 0;
    for(int i = index; i > 0; i -= i&(-i)){
        sum += BIT[i];
    }
    return sum;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    update(i, a[i]);
	}
	int q; // no of range sum queries
	cin>>q;
	for(int i=0;i<q;i++){
	    int type;
	    cin>>type;
	    int l, r;
	    cin>>l>>r;
	    if(type == 1){
	        update(l, r); // inrease the value at index l by r
	    }
	    else
	    cout<<"Sum of elements in range ["<<l<<" - "<<r<<"] is "<<(query(r) - query(l-1))<<"\n";
	}
	return 0;
}

