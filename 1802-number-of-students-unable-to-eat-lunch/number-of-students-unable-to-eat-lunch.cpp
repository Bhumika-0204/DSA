class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();
        
        for(int i = 0; i < n; i++){
            q.push(students[i]);
        }

        int i = 0, count = 0;

        while(!q.empty() && count < q.size()){   
            if(q.front() == sandwiches[i]){
                q.pop();
                i++;
                count = 0;                       
            }
            else{
                q.push(q.front());
                q.pop();
                count++;                         
            }
        }
        return q.size();
    }
};
