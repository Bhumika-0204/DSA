class Solution {
public:
     void dfs(int node,vector<vector<int>>&isConnected,vector<bool>&vis){
        vis[node]=true;
        for(int neighbour=0;neighbour<isConnected.size();neighbour++){
            if(isConnected[node][neighbour]==1 && !vis[neighbour]){
                dfs(neighbour,isConnected,vis);
            }
        }
     }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                provinces++;
                dfs(i,isConnected,vis);
            }
        }
        return provinces;
    }
};