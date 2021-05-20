#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Rabin Karp pattern matching algorithm
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string txt, pat;
	cin>>txt>>pat;
	int n = txt.size();
	int m = pat.size();
	
	ll hashPat = 0, hashTxt = 0, power = 1;
	// abc = a*(pow(256, 2)) + b*(pow(256, 1)) + c*(pow(256, 0)) = hashPat
	// aplcdefgh = a*(pow(256, 2)) + p*(pow(256, 1)) + l*(pow(256, 0)) = hashTxt
	for(int i=(m-1); i >= 0; i--){
	    hashPat = (hashPat + (power * pat[i]))%101;
	    hashTxt = (hashTxt + (power * txt[i]))%101;
	    if(hashPat < 0) hashPat += 101;
	    if(hashTxt < 0) hashTxt += 101;
	    if(i != 0){
	        power = (power * 256)%101;
	    }
	    if(power < 0) power += 101;
	}
	
	// we compare the hash of the strings if they are equal we check for the characters in them, if they
	// are also equal we found a match
	for(int i = 0; i <= (n-m); i++){
	    if(hashTxt == hashPat){
	        int f = 0;
	        for(int j = 0; j < m; j++){
	            if(pat[j] != txt[i + j]){
	                f=1;
	                break;
	            }
	        }
	        if(f == 0){
	            cout<<"Pattern found at index "<<i<<"\n";
	        }
	    }
	    // calculating for the next substring of string
	    // hashTxt -= (val of ith index);
	    // hashTxt *= 256
	    // hashTxt += (val at i+m index);
	    hashTxt = (hashTxt - txt[i]*power)%101;
	    if(hashTxt < 0) hashTxt += 101;
	    hashTxt = (hashTxt*256)%101;
	    if(hashTxt < 0) hashTxt += 101;
	    if(i != (n-m)){
	        hashTxt = (hashTxt + txt[i+m])%101;
	        if(hashTxt < 0) hashTxt += 101;
	    }
	}
	return 0;
}
