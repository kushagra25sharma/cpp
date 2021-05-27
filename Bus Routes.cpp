 // https://leetcode.com/problems/bus-routes/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int, vector<int>> m;
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                m[routes[i][j]].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        vector<int> vis(100001, 0);
        q.push({source, 0});
        while(q.size()){
            int num = q.front().first;
            int bus = q.front().second;
            q.pop();
            vis[num] = 1;
            if(num == target){
                return bus;
            }
            for(auto z : m[num]){
                for(auto i : routes[z]){
                    if(!vis[i]){
                        q.push({i, bus+1});
                    }
                }
                routes[z].clear();
            }
        }
        return -1;
    }
};
