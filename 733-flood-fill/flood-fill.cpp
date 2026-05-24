class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
    void dfs(vector<vector<int>>&image,int currRow,int currCol,int initialColour,int newColour){
        int n=image.size();
        int m=image[0].size();
        if(currRow<0 || currCol<0 || currRow>=n || currCol>=m) return;

        if(image[currRow][currCol]!=initialColour) return;

        image[currRow][currCol]=newColour;
        dfs(image,currRow+1,currCol,initialColour,newColour);
        dfs(image,currRow,currCol+1,initialColour,newColour);
        dfs(image,currRow-1,currCol,initialColour,newColour);
        dfs(image,currRow,currCol-1,initialColour,newColour);
    }
};