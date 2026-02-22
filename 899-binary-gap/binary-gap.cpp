class Solution {
public:
    int binaryGap(int n) {
        int l=-1;
        int p=0;
        int a=0;

        while(n>0){
            if(n&1){
                if(l!=-1){
                    a=max(a,p-l);
                }
                l=p;
            }
            p++;
            n>>=1;
        }
        return a;
    }
};