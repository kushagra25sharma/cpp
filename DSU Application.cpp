class Solution {
public:
    int index[100000];
    
    int find(int a){
        return index[a] == a ? a : (index[a] = find(index[a]));
    }
    
    void connect(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x == y){
            return;
        }
        index[x] = y;
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& a, vector<vector<int>>& q) {
        sort(a.begin(), a.end(), [](auto& l, auto& r) {return l[2] < r[2];});
        for(int i=0;i<q.size();i++){
            q[i].push_back(i);
        }
        for(int i=0;i<n;i++){
            index[i] = i;
        }
        sort(q.begin(), q.end(), [](auto& l, auto& r) {return l[2] < r[2];});
        vector<bool> ans(q.size());
        int i =0;
        for(int j=0;j<q.size();j++){
            int u = q[j][0], v = q[j][1], limit = q[j][2], ind = q[j][3];
            for(; i<a.size() && a[i][2] < limit ; i++){
                connect(a[i][0], a[i][1]);
            }
            int num1 = find(u);
            int num2 = find(v);
            ans[ind] = (num1 == num2);
        }
        return ans;
    }
};
