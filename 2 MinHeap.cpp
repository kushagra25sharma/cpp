class Solution {
    // https://leetcode.com/contest/weekly-contest-243/problems/process-tasks-using-servers/
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
        vector<int> ans(t.size(), 0);
        if(s.size() == 1){
            return ans;
        }
        priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> p, q;
        // p -> available servers
        // q -> servers which are busy
        for(int i=0;i<s.size();i++){
            p.push({0, s[i], i});
        }
        for(int i=0;i<t.size();i++){
            while((q.size() && q.top()[0] <= i) || p.size()==0){// if no available servers are present we take the busy server
                auto [tim, w, ind] = q.top();
                q.pop();
                p.push({tim <= i ? 0 : tim, w, ind});
            }
            auto [tim, w, ind] = p.top();
            p.pop();
            long num = max(tim*1l, i*1l);
            q.push({num + t[i], w, ind});
            ans[i] = ind;
        }
        return ans;
    }
};
