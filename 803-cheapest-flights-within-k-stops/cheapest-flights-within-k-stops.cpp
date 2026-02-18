class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &p:flights){
            adj[p[0]].push_back({p[1],p[2]});
        }

        vector<int> cost(n,INT_MAX);

        queue<tuple<int,int,int>> q;
        q.push({src,0,0});
        int minn=INT_MAX;

        while(!q.empty()){
            auto [u,s,price]=q.front();
            q.pop();
            if( u==dst ){
                minn=min(minn,price);
                continue;
            }
            if(s>k)continue;
            for(auto [v,p] :adj[u]){
                int newPrice=price+p;
                if(newPrice<cost[v] && s<=k){
                    cost[v]=newPrice;
                    q.push({v,s+1,newPrice});
                }
            }
        }

        return minn==INT_MAX?-1:minn;
    }
};