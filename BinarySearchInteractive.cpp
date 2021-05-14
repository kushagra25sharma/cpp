#include <bits/stdc++.h>
using namespace std;
#define ll long long
// C1, C2. Guessing the Greatest (easy & hard version) 703 DIV 2

int ques(int l, int r){
    if(l >= r){
        return -1;
    }
    cout<<"? "<<l+1<<" "<<r+1<<endl;
    int num;
    cin>>num;
    return (num-1);
}

int main() {
// 	ios_base :: sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    int n;
    cin>>n;
    cout<<"? 1 "<<n<<endl;
    int num;
    cin>>num;
    num -= 1;
    if(num == 0 || ques(0,num) != num){// max element is to right of 2nd max element right
        int l=num,r=n-1;
        while(r-l > 1){
            int m = (l+r)/2;
            int ans = ques(num,m);
            if(ans == num){
                r = m;
            } else{
                l = m;
            }
        }
        cout<<"! "<<r+1<<endl;
    } else {//left
        int l=0,r=num;
        while(r-l > 1){
            int m = (l+r)/2;
            int ans = ques(m,num);
            if(ans == num){
                l = m;
            } else{
                r = m;
            }
        }
        cout<<"! "<<l+1<<endl;
    }
	return 0;
}
