// https://leetcode.com/contest/weekly-contest-244/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        // eg s = 111000 for n^2 we will place the first char to the last n-1 times 110001 100011 000111 .... and calculate the best ans by 
        // comparing with 1010101.. and 01010101.. whichever gives the optimal result.
        // now if we add the string to itself we get 111000111000 now we can use sliding window technique.
        // 111000111000  & 111000111000
        // 101010101010  & 010101010101
        // we check for the first n elements and create arrays for both strings (starting with 0 & starting with 1)
        // in the next turn we shift the first element to last so subtract the prefix value from count and add the new count value
        s += s;
        int prefix1[2*n];
        int prefix2[2*n];
        string p = "", q= "";
        for(int i=0;i<2*n;i++){
            prefix1[i] = prefix2[i] = 0;
            if(i%2){
                p += '1';
                q += '0';
            }
            else{
                p += '0';
                q += '1';
            }
        }
        int ans = 1e7;
        int cnt1 = 0, cnt2 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == p[i]){
                prefix1[i] = 1;
                prefix2[i] = 0;
                cnt1++;
            }
            else{
                prefix1[i] = 0;
                prefix2[i] = 1;
                cnt2++;
            }
        }
        ans = min(ans, cnt1);
        ans = min(ans, cnt2);
        for(int i=n;i<2*n;i++){
            cnt1 -= prefix1[i-n];
            cnt2 -= prefix2[i-n];
            if(s[i] == p[i]){
                prefix1[i] = 1;
                prefix2[i] = 0;
                cnt1++;
            }
            else{
                prefix1[i] = 0;
                prefix2[i] = 1;
                cnt2++;
            }
            ans = min(ans, cnt1);
            ans = min(ans, cnt2);
        }
        return ans;
    }
};
