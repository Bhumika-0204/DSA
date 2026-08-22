class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0;
        int p=1;
        int nn=n;
        while(nn>0){
            int d=nn%10;
            s+=d;
            p*=d;
            nn/=10;


        }
        if(n%(s+p)==0) return true;
        else return false;
    }
};