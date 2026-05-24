class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;//agr current pixel ka colour or final colour same h to infinite loop na fase isliye
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
    void dfs(vector<vector<int>>&image,int currRow,int currCol,int initialColour,int newColour){
        int n=image.size();
        int m=image[0].size();
        if(currRow<0 || currCol<0 || currRow>=n || currCol>=m) return;//boundary condi check 

        if(image[currRow][currCol]!=initialColour) return; //colour match condi check

        image[currRow][currCol]=newColour; //colouring
        dfs(image,currRow+1,currCol,initialColour,newColour);
        dfs(image,currRow,currCol+1,initialColour,newColour);
        dfs(image,currRow-1,currCol,initialColour,newColour);
        dfs(image,currRow,currCol-1,initialColour,newColour);
    }
};