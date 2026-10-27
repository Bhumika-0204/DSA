class Solution {
public:
    int f(int n){
        int sum=0;
        while(n>0){
            int di=n%10;
            n=n/10;
            sum+=di*di;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        while(fast!=1){
            slow=f(slow);
            fast=f(f(fast));
        
            if(slow==fast && slow!=1){
                return false;
            }
        }
        return true;
    }
};