#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Painter Partition Problem
// Given an array in which ith element represent the length of ith board. Painting 1 unit of board takes 1 unit
// of time. Given k painters divide them such that the total time to complete the work is minimum. Each painter
// can only paint consecutive boards.

int countPainters(vector<int>& a, int maxTime){
    int sum = 0, n = a.size(), cnt = 1;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum > maxTime){ // if sum is greater than maxTime then that means the job of this painter is done
            cnt++;        //  and we will call the next painter.
            sum = a[i];
        }
    }
// returns the total no of painter needed to complete the job such that each of them painted at most for maxTime
    return cnt; 
}

int solve(vector<int>& a, int k){
    int n = a.size();
    int low = 0, high = 0;
    for(int i=0;i<n;i++){
        low = max(low, a[i]);
        high += a[i];
    }
    // low = max element of array high = sum of all elements. Our ans will lie in b/w this range 
    while(low < high){
        int mid = (low + high)/2;
        // count no of painters required to complete the job such that each take at most mid units of time
        int num = countPainters(a, mid); 
        if(num <= k){// we can decrease the time for each painter so that number of painters can increase
            high = mid;
        }
        else{ // we need to increase the time so that we can have the work done by atmost k painters
            low = mid + 1;
        }
    }
    return low;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	cout<<solve(a, k);
	return 0;
}
