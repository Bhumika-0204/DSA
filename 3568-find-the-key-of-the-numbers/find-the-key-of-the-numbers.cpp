class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans=0;
        int place=1;
        while(num1>0 || num2>0 || num3>0){
            int d1=num1%10;
            int d2=num2%10;
            int d3=num3%10;

            int mn=min({d1,d2,d3});
            ans+=mn*place;

            num1/=10;
            num2/=10;
            num3/=10;
            place*=10;
        }
        return ans;
    }
};