class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
            
        }
        int m=neg.size();
        int n=pos.size();
        vector<int>res(m+n);
        if(m==0){
            for(int i=0;i<nums.size();i++){
                nums[i]*=nums[i];
                
            }
            return nums;
        }
        else if(n==0){
            for(int i=0;i<nums.size();i++){
                nums[i]*=nums[i];

            }
            reverse(nums.begin(),nums.end());
            return nums;
        }
        else{
            for(int i=0;i<m;i++){
                neg[i]*=neg[i];
                
                
            }
            reverse(neg.begin(),neg.end());
            for(int i=0;i<n;i++){
                pos[i]*=pos[i];

            }
            int id=0,i=0,j=0;
            while(i<m && j<n){
                if(pos[j]>neg[i]){
                    res[id]=neg[i];
                    i++;
                    id++;
                }
                else{
                    res[id]=pos[j];
                    j++;
                    id++;

                }
                
            }
            while(i<m){
                    res[id]=neg[i];
                    i++;
                    id++;
                }
                while(j<n){
                    res[id]=pos[j];
                    j++;
                    id++;
                }
                return res;
        }
        return res;
    }
};