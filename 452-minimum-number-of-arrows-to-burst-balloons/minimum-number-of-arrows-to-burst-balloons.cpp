#include<print>
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int cnt=1;
        for(auto it:points){
            cout<<it[0]<<it[1]<<" ";
        }
        int m=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>m){
                cnt++;
                m=points[i][1];
            }
            m=min(points[i][1],m);
        }
        return cnt;
    }
};