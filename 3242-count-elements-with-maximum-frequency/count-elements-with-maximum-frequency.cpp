class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        int maxfreq=0;
        for(auto &p:freq){
            maxfreq=max(maxfreq,p.second);
        }
        int count=0;
        for(auto&p:freq){
            if(p.second==maxfreq){
                count+=p.second;
            }
        }
        return count;
    }
};