#include <bits/stdc++.h>
using namespace std;
#define ll long long
//Point sum query, Range update Binary Indexed tree
//Query: Get the value of element at given index  
//Update: add value v to all the elements in rangle [l.. r]
int n, BIT[100001], a[100001]; // 1 based indexing

void update(int index, int num){ // to increment index with val num
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
	    update(i+1, -a[i]);
	}
	int q; // no of range sum queries
	cin>>q;
	for(int i=0;i<q;i++){
	    int type;
	    cin>>type;
	    if(type == 1){
	        int l, r, val;
	        cin>>l>>r>>val;
	        update(l, val);
	        update(r+1, -val);
	    }
	    else{
	        int index;
	        cin>>index;
	        cout<<"Element at index "<<index<<" is "<<query(index)<<"\n";
	    }
	}
	return 0;
}

