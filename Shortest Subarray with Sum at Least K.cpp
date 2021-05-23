#include<bits/stdc++.h>
using namespace std;
// Leetcode: Shortest Subarray with Sum at Least K 
int shortestSubarray(vector<int> a, int K) {
        int N = a.size(), res = N + 1;
        deque<int> d;
        for (int i = 0; i < N; i++) {
            if (i > 0){
                a[i] += a[i - 1];
            }
                
            if (a[i] >= K){
                res = min(res, i + 1);
            }
                
            while (d.size() > 0 && a[i] - a[d.front()] >= K){
                res = min(res, i - d.front());
                d.pop_front();
            }
                
            while (d.size() > 0 && a[i] <= a[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }
        return res <= N ? res : -1;
    }
    
    int main(){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int k;
        cin>>k;
        cout<<shortestSubarray(a, k);
        return 0;
    }
