class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int res = 0;

        for(int i = 0; i < answers.size(); i++){
            int key = answers[i] + 1;

            if(mp[key] == 0){
                res += key;
                if(answers[i] == 0) continue;
                mp[key] = 1;
            }
            else{
                mp[key]++;
                if(mp[key] == key){
                    mp.erase(key);
                }
            }
        }
        return res;
    }
};