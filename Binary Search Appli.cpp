class Solution {
  // https://leetcode.com/contest/weekly-contest-228/problems/minimum-limit-of-balls-in-a-bag/
public:
    int minimumSize(vector<int>& a, int k) {
        int l = 1, r = 1000000000;
        while(l < r){
            // The search range is [1, 1000000000], per the problem constraints, so we set l and r accordintly.
            //The target is m = (l + r) / 2
            int mid = (l + r)/2;
            int sum = 0;
            //We then check if we can achieve the target with the number of operations we have. This is easy - we need to use (n - 1) / m  
            //operations to split each bag, and we check if it's not greater than max operations.
            // n = 20, target = 4: 4 + (4 + (4 + (4 + 4))) = 4 operations
            // n = 21, target = 4: 4 + (4 + (4 + (4 + (4 + 1)))) = 5 operations
            // n = 19, target = 4: 4 + (4 + (4 + (4 + 3))) = 4 operations
            for(int n : a){
                sum += ((n-1)/mid);
            }
            if(sum <= k){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
