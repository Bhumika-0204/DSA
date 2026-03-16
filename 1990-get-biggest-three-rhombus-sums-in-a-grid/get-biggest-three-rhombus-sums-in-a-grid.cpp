class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        set<int> sums;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                sums.insert(grid[i][j]);

                for(int k=1;;k++){

                    int r = i + 2*k;
                    int left = j - k;
                    int right = j + k;

                    if(r >= m || left < 0 || right >= n)
                        break;

                    int sum = 0;

                    int x=i, y=j;

                    for(int t=0;t<k;t++)
                        sum += grid[x+t][y+t];

                    x=i+k; y=j+k;
                    for(int t=0;t<k;t++)
                        sum += grid[x+t][y-t];

                    x=i+2*k; y=j;
                    for(int t=0;t<k;t++)
                        sum += grid[x-t][y-t];

                    x=i+k; y=j-k;
                    for(int t=0;t<k;t++)
                        sum += grid[x-t][y+t];

                    sums.insert(sum);
                }
            }
        }

        vector<int> res;

        for(auto it = sums.rbegin(); it!=sums.rend() && res.size()<3; it++)
            res.push_back(*it);

        return res;
    }
};