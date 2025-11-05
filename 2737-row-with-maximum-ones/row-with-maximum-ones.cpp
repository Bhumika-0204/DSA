class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int maxcount=0,maxrow=0;
        for(int i=0;i<n;i++){
            int count=countOnes(mat[i]);
            if(count>maxcount){
                maxcount=count;
                maxrow=i;
            }
            
  
        }
        return {maxrow,maxcount};
    }
    int countOnes(const vector<int>&row){
        return count(row.begin(),row.end(),1);
    }

};