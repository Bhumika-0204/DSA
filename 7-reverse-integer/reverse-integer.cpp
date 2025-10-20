class Solution {
public:
    int reverse(int x) {
        long long revno=0;
        while(x!=0){
            int rem=x%10;
            x=x/10;
            revno=(revno*10)+rem;
        }
        if (revno < INT_MIN || revno > INT_MAX)
            return 0;
        return revno;
    }

};