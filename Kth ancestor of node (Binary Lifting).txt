// Leetcode : kth ancestor of tree node
// Binary Lifting

class TreeAncestor {
    int LOG;
    vector<vector<int>> up; // 2D vextor for storing the ancestor of current vertex at 2^m levels up from it (0<=m<LOG)
    vector<int> depth; // to store the depth of current vertex from the root
public:
    // here in this question the tree is always rooted at 0
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;       
        while((1 << LOG) <= n){
            LOG++;
        }
        
        up = vector<vector<int>> (n, vector<int> (LOG));
        depth = vector<int> (n);
        parent[0] = 0; // parent of node 0 is 0. That means node 0 does not have any parent, it is the root
        
        // pre calculating all the ancestors of the current vertex at 2^j level above it where 0<=j<LOG (powers of 2)
        // so if we want to go up by 19 we can do by 16+2+1. This is called Binary Lifting
        
        // when the node are in sorted order 0->1->2->3 or 0->7->9->18 we are using this function otherwise we have to do dfs to fill the ancestors.
        for(int vertex = 0; vertex < n; vertex++){
            up[vertex][0] = parent[vertex];// initialising the parent one level above the current vertex
            if(vertex != 0){
                depth[vertex] = depth[parent[vertex]] + 1; // depth of current vertex will be 1 more than its parent
            }
            for(int j = 1; j < LOG; j++){
                up[vertex][j] = up[ up[vertex][j-1] ][j-1]; // the 2nd ancestor of cuurent vertex will be the 1st ancestor of current vertex's ancestor 
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k){ // if k is greater than the depth of vertex no ancestor exists
            return -1;
        }
        
        for(int i = LOG-1; i >= 0; i--){
            if(k >= (1 << i)){
                k -= (1 << i);
                node = up[node][i]; // the new value of node will be equal to the ancestor which is 1 << j level above the current node
            }
        }
        
        return node; // ancestor at k level up from the current vertex
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
