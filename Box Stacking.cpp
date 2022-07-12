// Link: https://practice.geeksforgeeks.org/problems/box-stacking/1/#

class Solution{
  public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int h[],int w[],int l[],int n)
    {
        //Your code here
        vector<vector<int>> v(3*n);
        int k = 0;
        for(int i=0;i<n;i++){
            v[k++] = {min(h[i], l[i]), max(h[i], l[i]), w[i]};
            v[k++] = {min(w[i], l[i]), max(w[i], l[i]), h[i]};
            v[k++] = {min(w[i], h[i]), max(w[i], h[i]), l[i]};
        }
        sort(v.begin(), v.end(), [](auto& l, auto& r){
            return (l[0]*l[1] > r[0]*r[1]);
        });
        n *= 3;
        vector<int> dp(n, 0);
        int maxi = 0;
        for(int i=0;i<n;i++){
            dp[i] = v[i][2];
            maxi = max(maxi, dp[i]);
        } 
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[j][0] > v[i][0] && v[j][1] > v[i][1]){
                    if(dp[j] + v[i][2] > dp[i]){
                        dp[i] = dp[j] + v[i][2];
                        maxi = max(maxi, dp[i]);
                    } 
                }
            }
        }
        return maxi;
    }
};
