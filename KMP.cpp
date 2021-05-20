#include <bits/stdc++.h>
using namespace std;
#define ll long long
// KMP pattern matchin algorithm 
// checks if the string pat appears as a substring in string txt
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string txt, pat;
	cin>>txt>>pat;
	if(txt.size() < pat.size()){
	    cout<<"-1";
	    return 0;
	}
	int m = pat.size();
	int lps[m]; // array to store the strings that are present as both prefix and suffix
	// abcdeabc
	// prefix: a, ab, abc, abcd, abcde, abcdea .....
	// suffix: c, bc, abc, eabc, deabc, cdeabc .....
	// only abc matches (it is present as both prefix and suffix)
	int i = 1;
	int len = 0;
	lps[0] = 0; // first letter won't match with anyone so lps[0] = 0
	while(i < m){
	    if(pat[len] == pat[i]){
	        len++;
	        lps[i] = len;
	        i++;
	    }
	    else{
	        if(len != 0){
	            len = lps[len-1];
	        }
	        else{
	            len++;
	            lps[i] = len;
	            i++;
	        }
	    }
	}
	i = 0; // for string txt
	int j = 0; // for string pat
	int n = txt.size();
	int f = 0;
	while(i < n){// Time complexity O(n+m) n for traversing txt string m for creating lps array
	    if(txt[i] == pat[j]){
	        i++;
	        j++;
	    }
	    if(j == m){
	        f = 1;
	        cout<<"Pattern found at index "<<(i-j)<<"\n";
	        j = lps[j-1];
	    }
	    else if(i < n && txt[i] != pat[j]){
	        if(j != 0){
	            j = lps[j-1];
	        }
	        else{
	            i++;
	        }
	    }
	}
	if(f == 0){
	    cout<<"No pattern found";
	}
	return 0;
}
