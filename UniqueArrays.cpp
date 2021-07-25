#include <bits/stdc++.h>
using namespace std;

// Your birthday is coming soon and one of your friends, Alex, is thinking about a gift for you. He knows 
// that you really like integer arrays with interesting properties.
// He selected two numbers, N and K and decided to write down on paper all integer arrays of length K
// (in form a[1], a[2], ..., a[K]), where every number a[i] is in range from 1 to N, and, moreover, a[i+1] is 
// divisible by a[i] (where 1 < i <= K), and give you this paper as a birthday present
// eg 3 2 => 5  (1, 1) (1, 2) (1, 3) (2, 2) (3, 3)

int rec(int i , int n , int k){
if ( i > n ) return 0;
if ( k == 0) return 1;
int x = rec(i, n , k-1);
int s = 0;
for(int j = 2 ; j*i <= n ; j++){
s+= rec(j*i , n , k-1);
}
return x + s;
}

int main (){
int n , k;
cin>>n>>k;
cout<<rec(1 , n , k)<<endl;
return 0;
}
