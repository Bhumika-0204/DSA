class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>visited;
        queue<int>q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            visited.insert(curr);
            for(int neighbours:rooms[curr]){
                if(visited.count(neighbours)==0){
                    q.push(neighbours);
                    visited.insert(neighbours);
                }
            }
        }
        return visited.size()==rooms.size();
    }
};