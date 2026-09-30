class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>f;
        vector<string>ans;
        for(int i=0;i+10<=s.size();i++){
            string sub=s.substr(i,10);
            f[sub]++;

            if(f[sub]==2){
            ans.push_back(sub);
            }
        
        }
        return ans;
    }
};