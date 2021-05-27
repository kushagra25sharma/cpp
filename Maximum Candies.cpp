// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;
        vector<int> vis(status.size(), 0);
        queue<int> q;
        for(int i=0;i<initialBoxes.size(); i++){
            int index = initialBoxes[i];
            if(status[index]){
                q.push(index);
            }
            else{
                vis[index] = 1;
            }
        }
            while(q.size()){
                int num = q.front();
                q.pop();

                ans += candies[num];
                for(int j=0;j<keys[num].size();j++){
                    if(!status[keys[num][j]] && vis[keys[num][j]]){
                        q.push(keys[num][j]);
                    }
                    status[keys[num][j]] = 1;
                }
                for(int j=0;j<containedBoxes[num].size();j++){
                        if(status[containedBoxes[num][j]]){
                            q.push(containedBoxes[num][j]);
                        }
                        else{
                            vis[containedBoxes[num][j]] = 1;
                        }
                }
            }
        return ans;
    }
};
