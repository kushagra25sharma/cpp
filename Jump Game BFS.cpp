// Jump Game Leetcode
// we are initially at 0th index we can jump an index i to any index j such that
// i + minJump <= j <= min(i + maxJump, s.length - 1), and s[j] == '0'

class Solution {
public:    
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        q.push(0);
        int maxi = 0; // the index of the farthest element we have visited
        while(q.size()){// using dfs so we don't visit the same index again
            int i = q.front();
            q.pop();
            // we have already visited farthest index so start from farthest index + 1 (maxi + 1) or i + minJump whichever is max
            int start = max(i + minJump, maxi + 1);
            int end =  min(i + maxJump, n-1);
            for(int index = start; index <= end; index++){
                if(s[index] == '0'){
                    q.push(index);
                    if(index == n-1){// we have reached index n-1 return true
                        return true;
                    }
                }
            }
            maxi = max(maxi, i + maxJump);
        }
        // if q is empty we didn't reach the n-1th index
        return false;
    }
};
